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
const int maxn=6005;

//i_am_noob
//#define wiwihorz  
#define y1 _y1

inline int area(int x1, int y1, int x2, int y2, int x3, int y3){
    return x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
}

int n,x[maxn],y[maxn],cnt[4][4][4],res;
short val[maxn][maxn];

void orzck(){
    cin >> n;
    rep(n) cin >> x[i] >> y[i];
    rep1(k,4){
        int cnt[4];
        rep(4) cnt[i]=0;
        rep(n) if(x[i]%2+y[i]%2*2==k) cnt[(x[i]/2)%2+(y[i]/2)%2*2]++;
        rep(4){
            res+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
            rep1(j,4) if(j!=i) res+=cnt[i]*(cnt[i]-1)/2*cnt[j];
        }
    }
    rep(n) rep2(j,i+1,n) val[i][j]=val[j][i]=abs(__gcd(x[j]-x[i],y[j]-y[i]))%4;
    rep(n){
        rep1(i1,4) rep1(i2,4) rep1(i3,4) cnt[i1][i2][i3]=0;
        rep1(j,n) if(i!=j){
            cnt[x[j]%4][y[j]%4][val[i][j]]++;
        }
        int tmp=0;
        rep1(x1,4) rep1(y1,4) rep1(x2,4) rep1(y2,4){
            if((x1%2==x[i]%2&&y1%2==y[i]%2)||x1%2!=x2%2||y1%2!=y2%2) continue;
            rep1(z1,4) rep1(z2,4){
                int val=0;
                if(x1!=x2||y1!=y2) val+=2;
                val-=z1+z2;
                val+=8;
                if(val&1) continue;
                val/=2;
                val=val+abs(area(x[i]%4,y[i]%4,x1,y1,x2,y2)/2)%2;
                if(val%2==0){
                    if(x1==x2&&y1==y2&&z1==z2) tmp+=cnt[x1][y1][z1]*(cnt[x1][y1][z1]-1);
                    else tmp+=cnt[x1][y1][z1]*cnt[x2][y2][z2];
                }
            }
        }
        res+=tmp/2;
    }
    print(res);
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