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

bool isnum(string s)
{
  if(SZ(s) == 1 && isdigit(s[0]))return 1;
  else if(s[0] == '0')return 0;
  for(char c:s)if(!isdigit(c))return 0;
  return 1;
}

ll usd[MAXn];

string d[MAXn];
ll tp[MAXn];

vector<ll> v[2][2]; // 0,1 = ex or reg , 0,1 = in another?
queue<ll> exq,regq;

vector<pair<string,string> > op;

int main()
{
    IOS();
    ll n,ctex=0;
    cin>>n;
    REP(i,n)cin>>d[i]>>tp[i],tp[i] = !tp[i];
    REP(i,n)if(tp[i] == 0)ctex++;

    REP(i,n)
    {
      if(isnum(d[i])){
        ll tmp = stoll(d[i]);
        if(tp[i] == 0)
        {
          if(tmp >=1 && tmp <= ctex)usd[tmp] = 1;
          else if(tmp > ctex && tmp <= n)usd[tmp] = 1,v[0][1].pb(i);
          else v[0][0].pb(i);
        }else{
          if(tmp >=1 && tmp <= ctex)usd[tmp] = 1,v[1][1].pb(i);
          else if(tmp > ctex && tmp <= n)usd[tmp] = 1;
          else v[1][0].pb(i);
        }
      }
      else{
        if(tp[i] == 0)v[0][0].pb(i);
        else v[1][0].pb(i);
      }
    }
    REP1(i,n)if(!usd[i])
    {
      if(i <= ctex)exq.push(i);
      else regq.push(i);
    }
    bool wt = 0;
    while(SZ(v[0][0]) || SZ(v[0][1]) || SZ(v[1][0]) || SZ(v[1][1])){
      debug(v[0][0],v[0][1],v[1][0],v[1][1],SZ(exq),SZ(regq),op);
      if(!SZ(exq) && !SZ(regq))
      {
        assert(SZ(v[0][1]) && SZ(v[1][1]));
        ll a = v[0][1].back(),b = v[1][1].back();
        v[0][1].pop_back();v[1][1].pop_back();
        op.pb({d[a],"bbb123"});
        op.pb({d[b],d[a]});
        wt = 1;
        exq.push(stoll(d[b]));
      }
      else if(SZ(exq))
      {
        ll t = exq.front();
        exq.pop();
        if(SZ(v[0][1]))
        {
          ll a = v[0][1].back();v[0][1].pop_back();
          op.pb({d[a],to_string(t)});
          regq.push(stoll(d[a]));
        }else{
          ll a = v[0][0].back();v[0][0].pop_back();
          op.pb({d[a],to_string(t)});
        }
      }
      else{
        ll t = regq.front();
        regq.pop();
        if(SZ(v[1][1]))
        {
          ll a = v[1][1].back();v[1][1].pop_back();
          op.pb({d[a],to_string(t)});
          exq.push(stoll(d[a]));
        }else{
          ll a = v[1][0].back();v[1][0].pop_back();
          op.pb({d[a],to_string(t)});
        }
      }
    }
    if(wt){
      ll t = exq.front();
      exq.pop();
      op.pb({"bbb123",to_string(t)});
    }
    cout<<SZ(op)<<endl;
    for(auto &pr:op)cout<<"move "<<pr.X<<" "<<pr.Y<<endl;
}