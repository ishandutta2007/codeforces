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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n, m, d[MAXn][MAXn], mx[MAXn], dg[MAXn];

ll g[MAXn];
ll fd(ll x){return g[x] = (g[x] == x?x:fd(g[x]));}
void mg(ll a,ll b)
{
    a = fd(a), b = fd(b);
    g[a] = b;
}

vector<ll> v[MAXn];

int main()
{
    IOS();
    cin>>n>>m;
    REP(i, n + m)g[i] = i;
    REP(i,n)
    {
        string s;
        cin>>s;
        REP(j, m)
        {
            if(s[j] == '>')d[i][j] = 1;
            else if(s[j] == '=')d[i][j] = 0, mg(i, n + j);
            else if(s[j] == '<')d[i][j] = -1;
            else assert(0);
        }
    }
    REP(i,n)REP(j,m)
    {
        if(d[i][j] == 1)v[fd(n+j)].pb(fd(i));
        else if(d[i][j] == -1)v[fd(i)].pb(fd(n+j));
    }
    REP(i, n+m)sort(ALL(v[i])), unique(ALL(v[i]));
    queue<ll> q;
    REP(i,n+m)mx[i] = -1;
    REP(i,n+m)for(ll x:v[i])dg[x]++;
    REP(i,n+m)if(dg[i] == 0)mx[i] = 1, q.push(i);
    REP(i,n+m)debug(i, fd(i), v[i]);
    while(SZ(q))
    {
        ll t = q.front();
        q.pop();
        debug(t);
        for(ll x:v[t])
        {
            mx[x] = max(mx[x], mx[t] + 1);
            dg[x]--;
            if(dg[x] == 0)q.push(x);
        }
    }
    REP(i,n+m)if(dg[i] != 0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    REP(i,n)cout<<mx[fd(i)]<<" ";
    cout<<endl;
    REP(i,m)cout<<mx[fd(i+n)]<<" ";
}