//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
template<typename _a,typename _b> ostream &operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
#else
#define debug(...)
//#define endl '\n'
#endif // brian
//}

const ll MAXn=1e3+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n;
ll c[10][2][MAXn];
vector<ll> q;
void ask()
{
    cout<<SZ(q)<<endl;
    REP(i,SZ(q))cout<<(i==0?"":" ")<<q[i]+1;
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,10)
    {
        REP(j,2)
        {
            q.resize(0);
            REP(k,n)
            {
                if(((k&(1<<i))>0)==j)q.pb(k);
            }
            if(SZ(q))
            {
                ask();
                REP(k,n)cin>>c[i][j][k];
            }
            else REP(k,n)c[i][j][k]=INF;
        }
    }
    q.resize(0);
    REP(i,n)
    {
        ll ans=INF;
        REP(j,10)ans=min(ans,c[j][!((i&(1<<j))>0)][i]);
        q.pb(ans);
    }
    cout<<-1<<endl;
    REP(i,SZ(q))cout<<(i==0?"":" ")<<q[i];
    cout<<endl;
}