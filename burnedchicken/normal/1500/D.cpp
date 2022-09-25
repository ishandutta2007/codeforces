#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
inline char readchar(){
    const int maxn=1000000;
    static char buf[maxn],*p=buf,*q=buf;
    if(p==q&&(q=(p=buf)+fread(buf,1,maxn,stdin))==buf) return EOF;
    else return *p++;
}
inline int readint(){
    int c=readchar(),x=0,neg=0;
    while((c<'0'||c>'9')&&c!='-'&&c!=EOF) c=readchar();
    if(c=='-') neg=1,c=readchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=readchar();
    return neg?-x:x;
}
const int maxn=1505;

//i_am_noob
//#define wiwihorz  
int n,m,a[maxn][maxn],val[maxn][maxn],ans[maxn];
vector<pii> vec1[maxn],vec2[maxn],vec3[maxn],vec4;
bool vis[maxn*maxn];

void hhhhauraorz(){
    n=readint(),m=readint();
    rep(n) rep1(j,n) a[i][j]=readint();
    rep(n) val[i][0]=val[0][i]=1;
    rep(n) vec1[i].pb({0,a[0][i]}),vec2[i].pb({0,a[0][i]});
    rep2(i,1,n){
        vec4.clear();
        vec4.pb({0,a[i][0]});
        vector<pii> tmp,tmp2;
        bool flag;
        vector<pii> vec5;
        int cnt;
        rep2(j,1,n){
            tmp.clear();
            tmp.pb({0,a[i][j]});
            int cur1=0,cur2=0,cur3=0,minid;
            pii minn;
            while(cur1<sz(vec2[j-1])||cur2<sz(vec1[j])||cur3<sz(vec4)){
                minn={inf,0};
                if(cur1<sz(vec2[j-1])&&vec2[j-1][cur1]<minn) minn=vec2[j-1][cur1],minid=1;
                if(cur2<sz(vec1[j])&&vec1[j][cur2]<minn) minn=vec1[j][cur2],minid=2;
                if(cur3<sz(vec4)&&vec4[cur3]<minn) minn=vec4[cur3],minid=3;
                tmp.pb({minn.first+1,minn.second});
                if(minid==1) cur1++;
                if(minid==2) cur2++;
                if(minid==3) cur3++;
            }
            cnt=0;
            tmp2.clear();
            for(auto& [x,y]: tmp){
                if(vis[y]) continue;
                vis[y]=1;
                cnt++;
                tmp2.pb({x,y});
                if(cnt>m){
                    val[i][j]=x;
                    break;
                }
            }
            for(auto& [x,y]: tmp) vis[y]=0;
            if(cnt<=m) val[i][j]=min(i,j)+1;
            val[i][j]=min(val[i][j],min(i,j)+1);
            vec3[j]=tmp2;
            vec5.clear();
            vec5.pb({0,a[i][j]});
            for(auto& [x,y]: vec4) if(y!=a[i][j]) vec5.pb({x+1,y});
            vec4=vec5;
            if(sz(vec4)>m+1) vec4.pop_back();
        }
        vec2[0]={{0,a[i][0]}};
        rep2(j,1,n) vec2[j]=vec3[j];
        rep1(j,n){
            vec5.clear();
            vec5.pb({0,a[i][j]});
            for(auto& [x,y]: vec1[j]) if(y!=a[i][j]) vec5.pb({x+1,y});
            vec1[j]=vec5;
            if(sz(vec1[j])>m+1) vec1[j].pop_back();
        }
    }
    rep(n) rep1(j,n) ans[val[i][j]]++;
    rep3(i,n-1,1) ans[i]+=ans[i+1];
    rep(n) rep1(j,n) bug(i,j,val[i][j]);
    rep2(i,1,n+1) print(ans[i]);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}