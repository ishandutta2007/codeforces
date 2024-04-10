#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define inf 1010000000
//#define inf 4000000000000000000
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
#define wiwihorz  

int n,res[maxn],ans[maxn],cnt;
ykh;
vector<int> vec[maxn];
bool vis[maxn];

int query(int x, int y, int z){
    if(cnt==0) assert(0);
    cnt--;
    int res;
    #ifdef i_am_noob
    int a[3];
    a[0]=abs(ans[x]-ans[y]);
    a[1]=abs(ans[y]-ans[z]);
    a[2]=abs(ans[z]-ans[x]);
    sort(a,a+3);
    return a[1];
    #else
    print("?",x+1,y+1,z+1);
    cout << flush;
    cin >> res;
    #endif
    return res;
}

void report(){
    #ifdef i_am_noob
    bool flag=1;
    rep(n) if(ans[i]!=res[i]) flag=0;
    //rep(n) bug(i,res[i],ans[i]);
    if(!flag) print(flag),bug(0);
    #else
    print0("!");
    rep(n) print0(res[i]+1);
    cout << endl;
    int x;
    cin >> x;
    #endif
}

void orzck(){
    #ifdef i_am_noob
    n=1000;
    #else
    cin >> n;
    #endif
    cnt=2*n+420;
    #ifdef i_am_noob
    rep(n) ans[i]=i;
    shuffle(ans,ans+n,rng);
    if(ans[0]>ans[1]) rep(n) ans[i]=n-1-ans[i];
    #endif
    uniform_int_distribution<int> dis(0,n-1);
    int x,y,z,val=1;
    while(val<=2){
        x=dis(rng),y=dis(rng),z=dis(rng);
        while(y==x) y=dis(rng);
        while(z==x||z==y) z=dis(rng);
        val=query(x,y,z);
    }
    //bug(val);
    rep1(_,5){
        int minn=inf,minid=-1;
        rep1(__,80){
            z=dis(rng);
            while(z==x||z==y) z=dis(rng);
            int tmp=query(x,y,z);
            if(tmp<minn) minn=tmp,minid=z;
        }
        if(minid!=-1) y=minid;
    }
    bug(ans[x],ans[y]);
    rep(n) vec[i].clear();
    rep(n) vis[i]=0,res[i]=0;
    rep(n) if(i!=x&&i!=y) vec[query(x,y,i)].pb(i);
    val=-1;
    rep(n) if(sz(vec[i])){
        if(i==1){
            if(sz(vec[1])==1&&sz(vec[2])>=2) val=2;
            else val=1;
            break;
        }
        val=2*i+1-sz(vec[i]);
        break;
    }
    //assert(val==abs(ans[x]-ans[y]));
    int k;
    rep(n) if(sz(vec[i])){
        k=vec[i][0];
        break;
    }
    if(val==1){
        bool flag=0;
        res[x]=0,res[y]=1;
        int tmp[2];
        tmp[0]=tmp[1]=-1;
        rep(sz(vec[2])) tmp[i]=query(x,k,vec[2][i]);
        if(tmp[0]==2||tmp[1]==2) res[k]=2;
        else res[k]=-1;
        if(sz(vec[1])>1) res[vec[1][1]]=1-res[k];
        if(res[k]==2){
            if(sz(vec[1])==1) flag=1;
            else k=vec[1][1];
        }
        rep2(i,2,n){
            for(auto j: vec[i]){
                if(flag) res[j]=i+1;
                else{
                    int tmp=query(x,k,j);
                    if(tmp>i) res[j]=i+1;
                    else res[j]=-i;
                }
            }
        }
        bug('a');
    }
    else{
        res[x]=0,res[y]=val;
        vis[x]=vis[y]=1;
        rep2(i,val+1,n){
            for(auto j: vec[i]){
                if(query(x,k,j)>i) res[j]=i+val;
                else res[j]=-i;
                vis[j]=1;
            }
        }
        x=min_element(res,res+n)-res;
        int minn=inf;
        rep(n) if(res[i]!=res[x]&&res[i]<minn) minn=res[i],y=i;
        if(res[y]<0){
            rep(n) if(!vis[i]){
                res[i]=res[y]+query(x,y,i);
            }
        }
        else{
            x=max_element(res,res+n)-res;
            int maxx=-inf;
            rep(n) if(res[i]!=res[x]&&res[i]>maxx) maxx=res[i],y=i;
            rep(n) if(!vis[i]){
                res[i]=res[y]-query(x,y,i);
            }
        }
    }
    
    x=*min_element(res,res+n);
    //rep(n) bug(i,res[i]);
    //bug(x);
    rep(n) res[i]-=x;
    if(res[0]>res[1]) rep(n) res[i]=n-1-res[i];
    report();
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
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