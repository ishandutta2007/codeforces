#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

template<int maxn>
struct NT{
    vector<signed> pr;
    signed lpd[maxn];
    NT(){
        pr.clear();
        rep(maxn) lpd[i]=-1;
        rep2(i,2,maxn){
            if(lpd[i]==-1) lpd[i]=i,pr.pb(i);
            for(auto p: pr){
                if(p*i>=maxn) break;
                lpd[p*i]=p;
                if(i%p==0) break;
            }
        }
    }
    inline bool isp(int x){return lpd[x]==x;}
    signed fac_cnt(signed x){
        assert(x>=1&&x<maxn);
        signed res=1,lst=0,cur=0;
        while(x>1){
            signed p=lpd[x];
            if(p!=lst) res*=cur+1,cur=0;
            cur++;
            lst=p;
            x/=p;
        }
        return res*(cur+1);
    }
};
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=32000005,maxm=1000001,maxk=7777714;
    
//i_am_noob
#define wiwihorz  
NT<maxn> nt;
set<int> st;
map<int,vector<int>> factors;
map<int,int> mm;
vector<vector<bool>> res1;
vector<vector<int>> res2;
int cur=0;

void prep(int x){
    int m=x;
    for(auto p: nt.pr){
        if(m%p==0) factors[x].pb(p);
        while(m%p==0) m/=p;
    }
    if(m>1) factors[x].pb(m);
    bug(x),bug(factors[x]);
    if(sz(factors[x])<=2) return;
    vector<int> vec=factors[x];
    mm[x]=cur++;
    if(vec[0]*vec[1]<=maxm){
        vector<bool> dp(vec[0]*vec[1]+1);
        dp[0]=1;
        rep(vec[0]*vec[1]+1) if(dp[i]){
            for(auto p: vec) if(i+p<vec[0]*vec[1]+1) dp[i+p]=1;
        }
        res1.pb(dp);
        res2.pb({});
    }
    else{
        assert(sz(vec)<=4);
        vector<int> dis(vec[0]);
        vector<bool> vis(vec[0]);
        queue<pii> q[3];
        rep2(i,1,vec[0]) dis[i]=inf;
        q[0].push({0,0});
        while(1){
            int id=-1,minn=inf;
            rep(3) if(!q[i].empty()) if(q[i].front().first<minn) minn=q[i].front().first,id=i;
            if(id==-1) break;
            int u=q[id].front().second;
            q[id].pop();
            if(vis[u]) continue;
            vis[u]=1;
            //bug(u);
            rep2(i,1,sz(vec)){
                int v=(u+vec[i])%vec[0];
                if(dis[u]+vec[i]<dis[v]){
                    dis[v]=dis[u]+vec[i];
                    q[i-1].push({dis[v],v});
                }
            }
        }
        //bug(dis);
        res2.pb(dis);
        res1.pb({});
        bug(factors[x][0]);
    }
}

int inverse(int x, int p){
    int res=1,b=p-2;
    while(b){
        if(b&1) res=res*x%p;
        x=x*x%p,b>>=1;
    }
    return res;
}

bool query(int n, int k){
    if(k==1) return false;
    bug(k),bug(factors[k]);
    vector<int> vec=factors[k];
    bug(vec);
    if(sz(vec)==1) return n%vec[0]==0;
    if(n>=vec[0]*vec[1]) return true;
    if(sz(vec)==2){
        int y=(__int128(n))*inverse(vec[1]%vec[0],vec[0])%vec[0];
        return (__int128(vec[1]))*y<=n;
    }
    if(vec[0]*vec[1]<=maxm){
        return res1[mm[k]][n];
    }
    else{
        bug(res2[mm[k]][n%vec[0]]);
        return res2[mm[k]][n%vec[0]]<=n;
    }
    return true;
}

void orzck(){
    int n,k;
    cin >> n >> k;
    if(!st.count(k)){
        prep(k);
        st.insert(k);
    }
    print(query(n,k)?"YES":"NO");
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}