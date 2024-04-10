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
int n,s,cnt[maxn];
vector<int> vec[maxn];

void orzck(){
    cin >> n >> s;
    if(s<2*n-1||s>n*(n+1)/2){
        print("No");
        return;
    }
    rep2(i,1,n){
        cnt[0]=1;
        int k=n-1;
        int tot=1;
        int cur;
        rep2(j,1,n){
            cnt[j]=min(cnt[j-1]*i,k);
            k-=cnt[j];
            tot+=(j+1)*cnt[j];
            if(!k){
                cur=j;
                break;
            }
        }
        if(tot<=s){
            bug(i,tot,cur);
            rep1(j,n) bug(cnt[j]);
            rep3(j,n-1,1){
                if(tot==s) break;
                while(cnt[j]>1){
                    if(tot==s) break;
                    if(s-tot>=(cur+1)-j){
                        cnt[j]--;
                        cnt[cur+1]++;
                        cur++;
                        tot+=cur-j;
                    }
                    else{
                        cnt[j]--;
                        cnt[j+(s-tot)]++;
                        cur++;
                        tot+=s-tot;
                    }
                }
            }
            rep1(j,n) bug(cnt[j]);
            cur=0;
            rep1(j,n) rep1(de,cnt[j]) vec[j].pb(cur++);
            print("Yes");
            rep2(j,1,n) rep1(de,cnt[j]) print0(vec[j-1][de/i]+1);
            cout << "\n";
            return;
        }
        else rep(cur+1) cnt[i]=0;
    }
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