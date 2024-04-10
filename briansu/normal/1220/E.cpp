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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn];
vector<ll> v[MAXn], v2[MAXn];

ll dph[MAXn], top[MAXn], g[MAXn], git = 0, sum[MAXn], ct[MAXn];
vector<ll> his;


void dfs(ll now, ll f){
    top[now] = dph[now];
    his.pb(now);
    for(auto k:v[now])if(k != f){
        if(dph[k] != -1)top[now] = min(top[now], dph[k]);
        else {
            dph[k] = dph[now] + 1;
            dfs(k, now);
            top[now] = min(top[now], top[k]);
        }
    }
    if(top[now] == dph[now]){
        ll lst = -1;
        do {
            lst = his.back();
            his.pop_back();
            g[lst] = git;
        } while(lst != now);
        git ++;
    }
}

ll dp[MAXn][2], canrt[MAXn];

void dfs2(ll now,ll f){
    if(ct[now] > 1)canrt[now] = 1;
    ll nrtmx = 0;
    for(auto k:v2[now])if(k != f){
        dfs2(k, now);
        if(canrt[k])canrt[now] = 1, dp[now][1] += dp[k][1];
        nrtmx = max(nrtmx, dp[k][0] - dp[k][1]);
    }
    if(!canrt[now])nrtmx += sum[now];
    else dp[now][1] += sum[now];
    dp[now][0] = dp[now][1] + nrtmx;
}


int main()
{
    IOS();
    ll n, m, s;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> d[i];
    for(int i = 1;i <= m;i ++){
        ll a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cin >> s;
    memset(dph, -1, sizeof(dph));
    dph[1] = 0;
    dfs(1, -1);

    for(int i = 1;i <= n;i ++)
        for(auto k:v[i])if(g[i] != g[k])
            v2[g[i]].pb(g[k]);
    
    for(int i = 1;i <= n;i ++)
        sum[g[i]] += d[i], ct[g[i]]++;
    
    dfs2(g[s], -1);
    cout << dp[g[s]][0] << endl;
}