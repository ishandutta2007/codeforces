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


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

bool c[MAXn][MAXn];

ll diss[MAXn],dist[MAXn];

int main()
{
    IOS();
    ll n,m,s,t;
    cin>>n>>m>>s>>t;
    REP(i,m)
    {
      ll a,b;
      cin>>a>>b;
      c[a][b]=c[b][a]=1;
    }
    REP1(i,n)diss[i]=dist[i]=INF;
    queue<ll> q;
    q.push(s);
    diss[s]=0;
    while(SZ(q))
    {
      ll p=q.front();
      q.pop();
      REP1(i,n)if(c[p][i]&&diss[i]==INF)
      {
        diss[i]=diss[p]+1;
        q.push(i);
      }
    }

    q.push(t);
    dist[t]=0;
    while(SZ(q))
    {
      ll p=q.front();
      q.pop();
      REP1(i,n)if(c[p][i]&&dist[i]==INF)
      {
        dist[i]=dist[p]+1;
        q.push(i);
      }
    }
    pary(diss+1,diss+1+n);
    pary(dist+1,dist+1+n);
    ll tt=0,g=diss[t];
    REP1(i,n)for(int j=1;j<i;j++)if(i!=j&&!c[i][j])
    {
      if(diss[i]+1+dist[j]>=g&&diss[j]+1+dist[i]>=g)tt++;
    }
    cout<<tt<<endl;
}