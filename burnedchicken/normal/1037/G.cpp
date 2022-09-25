#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

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
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=100005;

//i_am_noob
//#define wiwihorz  
int n,lst[49],nxt[maxn][28],pre[maxn][28],cnt,niml[maxn][28],nimr[maxn][28],sum[maxn];
vector<int> vec[49];
string str;
bool ok;

int solve(int l, int r, bool flag=0){
    if(l>r) return 0;
    int k;
    if(!flag){
        k=l==0?26:str[l-1]-'a';
        if(niml[r][k]!=-1) return niml[r][k];
    }
    else{
        k=r==n-1?26:str[r+1]-'a';
        if(nimr[l][k]!=-1) return nimr[l][k];
    }
    bool de[49],good[49];
    memset(de,0,sizeof de);
    memset(good,0,sizeof good);
    rep(26){
        int k1=nxt[l][i],k2=pre[r+1][i];
        if(k1>r) continue;
        int cur=solve(l,k1-1,1)^solve(k2+1,r);
        cnt++;
        if(ok){
            cur^=sum[k2]^sum[k1];
        }
        else{
            for(int j=k1; j<k2; j=nxt[j+1][i]) cur^=solve(j+1,nxt[j+1][i]-1),cnt++;
        }
        
        good[cur]=1;
    }
    rep(49) if(!good[i]){
        if(!flag) niml[r][k]=i;
        else nimr[l][k]=i;
        return i;
    }
    return 49;
}

void orzck(){
    ld start=clock();
    cnt=0;
    cin >> str;
    n=sz(str);
    rep(n) vec[str[i]-'a'].pb(i);
    rep(49) lst[i]=n;
    rep(maxn) rep1(j,28) niml[i][j]=nimr[i][j]=-1;
    rep(28) nxt[n][i]=n,pre[0][i]=-1;
    rep3(i,n-1,0) rep1(j,28){
        if(j==str[i]-'a') nxt[i][j]=i;
        else nxt[i][j]=nxt[i+1][j];
    }
    rep(n) rep1(j,28){
        if(j==str[i]-'a') pre[i+1][j]=i;
        else pre[i+1][j]=pre[i][j];
    }
    //rep(n+1) rep1(j,2) bug(i,j,pre[i][j],nxt[i][j]);
    rep(26) if(sz(vec[i])){
        sum[vec[i][0]]=0;
        rep1(j,sz(vec[i])-1) sum[vec[i][j+1]]=sum[vec[i][j]]^solve(vec[i][j]+1,vec[i][j+1]-1);
    }
    ok=1;
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        bool good[49];
        memset(good,0,sizeof good);
        rep(26) if(sz(vec[i])){
            int k1=nxt[l][i],k2=pre[r+1][i];

            if(k1>r) continue;
            int cur=solve(l,k1-1,1)^solve(k2+1,r);
            cur^=sum[k1]^sum[k2];
            good[cur]=1;
        }
        print(good[0]?"Alice":"Bob");
    }
    bug((clock()-start)/CLOCKS_PER_SEC);
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