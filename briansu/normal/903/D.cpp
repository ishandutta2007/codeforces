#ifndef BIGINT
#define BIGINT
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
class bigint{
typedef long long ll;

private:
  const ll base=1000000,ln=6;
  std::vector<ll> d;
  bool neg;
public:
  bigint():neg(0){};
  bigint(ll di);
  bigint(std::string di);
  ~bigint();
  bool s()const{
    return neg;
  }
  bool &sref(){
    return neg;
  }
  int size()const{
    return (int)d.size();
  }
  void shrink()
  {
    while(d.size()&&!d.back())d.pop_back();
  }
  void resize(int sz)
  {
    d.resize(sz,0);
  }
  bigint &operator = (const bigint &_d)
  {
    d=_d.d;
    neg=_d.s();
    return (*this);
  }
  friend std::ostream &operator << (std::ostream&,const bigint&);
  friend std::istream &operator >> (std::istream&,const bigint&);
  ll &operator [](size_t t)
  {
    if(d.size()<=t)d.resize(t+1,0);
    return d[t];
  }
  ll get(size_t t)const
  {
    if(d.size()<=t)return 0;
    else return d[t];
  }
  void adj(int l,int r)
  {
    bigint &a=(*this);
    for(int i=l;i<r;i++)
    {
      if(a[i]<0||a[i]>=base)
      {
        a[i+1]+=a[i]/base;
        a[i]%=base;
        if(a[i]<0)a[i+1]--,a[i]+=base;
      }
    }
  }
  int cmp(const bigint &b)const
  {
    const bigint &a=(*this);
    int fg;
    if(a.s()^b.s())return (a.s()?-1:1);
    else fg=(a.s()?-1:1);
    if(a.size()!=b.size())return (a.size()>b.size()?fg:-fg);
    for(int i=a.size()-1;i>=0;i--)
    {
      if(a.get(i)==b.get(i))continue;
      else if(a.get(i)>b.get(i))return fg;
      else return -fg;
    }
    return 0;
  }
  bool operator < (const bigint &b)const{
      return cmp(b)<0;
  }
  bool operator > (const bigint &b)const{
      return cmp(b)>0;
  }
  bool operator == (const bigint &b)const{
      return cmp(b)==0;
  }
  bool operator <= (const bigint &b)const{
      return cmp(b)<=0;
  }
  bool operator >= (const bigint &b)const{
      return cmp(b)>=0;
  }
  bigint operator + (const bigint &b)const;
  bigint operator - (const bigint &b)const;
  bigint operator - ()const;
  bigint operator * (const bigint &b)const;
  bigint operator / (const bigint &b)const;
  bigint operator % (const bigint &b)const
  {
    return (*this)-((*this)/b)*b;
  }
  bigint operator += (const bigint &b)
  {
    return (*this)=(*this)+b;
  }
  bigint operator -= (const bigint &b)
  {
    return (*this)=(*this)-b;
  }
  bigint operator *= (const bigint &b)
  {
    return (*this)=(*this)*b;
  }
  bigint operator /= (const bigint &b)
  {
    return (*this)=(*this)/b;
  }
  bigint operator %= (const bigint &b)
  {
    return (*this)=(*this)%b;
  }
};

bigint::bigint(ll di)
{
  if(di<0)neg=1,di=-di;
  else neg=0;
  while(di>0)
  {
    d.push_back(di%base);
    di/=base;
  }
}

bigint::bigint(std::string di)
{
  if(di[0]=='-')neg=1,di=di.substr(1);
  else neg=0;
  std::reverse(di.begin(),di.end());
  ll tmp=0,bs=1;
  for(char c:di)
  {
    tmp=tmp+bs*(c-'0');
    bs*=10;
    if(bs>=base)
    {
      d.push_back(tmp);
      tmp=0;bs=1;
    }
  }
  if(tmp)d.push_back(tmp);
  this->shrink();
}

bigint::~bigint()
{
  d.clear();
  d.shrink_to_fit();
}

std::ostream &operator << (std::ostream &_ss,const bigint &d)
{
  if(!d.size())
  {
    _ss<<"0";
    return _ss;
  }
  if(d.s())_ss<<"-";
  _ss<<d.d.back();
  for(int i=d.size()-2;i>=0;i--)_ss<<std::setw(d.ln)<<std::setfill('0')<<d.d[i];
  return _ss;
}

std::istream &operator >> (std::istream &_ss,bigint &d)
{
  std::string s;
  _ss>>s;
  d=bigint(s);
  return _ss;
}

bigint bigint::operator + (const bigint &b)const{
  const bigint &a=(*this);
  if(a.s())return b-(-a);
  if(b.s())return a-(-b);
  bigint rt;
  ll t=std::max(a.size(),b.size());
  rt.resize(t+1);
  for(int i=0;i<t;i++)rt[i]=a.get(i)+b.get(i);
  rt.adj(0,t);
  rt.shrink();
  return rt;
};
bigint bigint::operator - (const bigint &b)const{
  const bigint &a=(*this);
  if(b.s())return a+(-b);
  if(a.s())return -((-a)+b);
  if(a<b)return -(b-a);
  bigint rt;
  ll t=std::max(a.size(),b.size());
  rt.resize(t+1);
  for(int i=0;i<t;i++)rt[i]=a.get(i)-b.get(i);
  rt.adj(0,t);
  rt.shrink();
  return rt;
};
bigint bigint::operator - ()const{
  bigint rt=(*this);
  rt.sref()=!rt.s();
  return rt;
}
bigint bigint::operator * (const bigint &b)const{
  const bigint &a=(*this);
  bigint rt;
  ll t=a.size()+b.size();
  rt.resize(t+1);
  rt.sref()=a.s()^b.s();
  for(int i=0;i<a.size();i++)
    for(int j=0;j<b.size();j++)rt[i+j]+=a.get(i)*b.get(j);
  rt.adj(0,t);
  rt.shrink();
  return rt;
};
bigint bigint::operator / (const bigint &b)const{
  const bigint &a=(*this);
  bigint rt;
  int t=std::max(a.size()-b.size()+1,0);
  rt.resize(t);
  rt.sref()=a.s()^b.s();
  if(!b.size())return bigint();
  else if(b.size()==1)
  {
    ll tmp=0,dv=b.get(0);
    for(int i=a.size()-1;i>=0;i--)
    {
      tmp=tmp*base+a.get(i);
      rt[i]=tmp/dv;
      tmp%=dv;
    }
    rt.shrink();
    return rt;
  }
  bigint a2=a;
  ll tmpb=b.get(b.size()-1)*base+b.get(b.size()-2);
  for(int i=t-1;i>=0;i--)
  {
    ll tmpa=a2.get(i+b.size())*base*base+a2.get(i+b.size()-1)*base+a2.get(i+b.size()-2);
    rt[i]=std::max(tmpa/tmpb-1,0LL);
    for(int j=b.size()-1;j>=0;j--)a2[i+j]-=rt[i]*b.get(j);
    a2.adj(i,i+b.size());
    bool ok=1;
    for(int j=b.size();j>=0;j--)
    {
      if(a2.get(i+j)==b.get(j))continue;
      else if(a2.get(i+j)>b.get(j))ok=1;
      else ok=0;
      break;
    }
    if(ok)
    {
      rt[i]++;
      for(int j=b.size()-1;j>=0;j--)a2[i+j]-=b.get(j);
      a2.adj(i,i+b.size());
    }
  }
  rt.adj(0,t);
  rt.shrink();
  return rt;
};
#endif


//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


map<ll,ll> mp;


int main()
{
    IOS();
    ll n;
    cin>>n;
    bigint tt=0,ans=0;
    REP(i,n)
    {
      ll t;
      cin>>t;
      ll a=mp[t-1],b=mp[t],c=mp[t+1];
      ll ct=i-a-b-c;
      ans+=bigint(ct*t)-(tt-bigint(a*(t-1)+b*t+c*(t+1)));
      tt+=bigint(t);
      mp[t]++;
    }
    cout<<ans<<endl;
}