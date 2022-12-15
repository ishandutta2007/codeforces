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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll par[MAXn][MAXlg],mx[MAXn][MAXlg],sum[MAXn][MAXlg],d[MAXn];
ll nit=1;

int main()
{
    IOS();
    FILL(par,-1);
    FILL(mx,-1);
    FILL(sum,-1);
    ll Q,last=0;
    cin>>Q;
    while(Q--)
    {
      ll tp,p,q;
      cin>>tp>>p>>q;
      p^=last;
      q^=last;
      debug(tp,p,q);
      if(tp==1)
      {
        nit++;
        ll t=nit;
        d[t]=q;
        ll nxt;
        if(d[p]>=d[t])nxt=p;
        else
        {
          ll now=p;
          for(int i=MAXlg-1;i>=0;i--)if(mx[now][i]!=-1&&mx[now][i]<q)now=par[now][i];
          nxt=par[now][0];
        }
        if(nxt!=-1)
        {
          par[t][0]=nxt;
          mx[t][0]=d[nxt];
          sum[t][0]=d[nxt];
          for(int i=1;i<MAXlg;i++)if(par[par[t][i-1]][i-1]!=-1)
          {
            par[t][i]=par[par[t][i-1]][i-1];
            mx[t][i]=max(mx[t][i-1],mx[par[t][i-1]][i-1]);
            sum[t][i]=sum[t][i-1]+sum[par[t][i-1]][i-1];
          }else break;
        }
      }
      else{
        if(d[p]>q)
        {
          cout<<0<<endl;
          last=0;
          continue;
        }
        q-=d[p];
        ll tt=1,now=p;
        for(int i=MAXlg-1;i>=0;i--)if(sum[now][i]!=-1&&sum[now][i]<=q)tt+=(1<<i),q-=sum[now][i],now=par[now][i];
        debug(now);
        cout<<tt<<endl;
        last=tt;
      }
    }
}