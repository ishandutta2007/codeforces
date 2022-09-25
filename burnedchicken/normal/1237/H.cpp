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
const int maxn=2005;

//i_am_noob
#define wiwihorz  
int n,cnt1[3],cnt2[3],m,a[maxn],b[maxn],r[maxn],pos[maxn];
string str1,str2;
vector<int> res;

void op(int x){
    bug(x);
    int k=r[x];
    res.pb(2*(k+1));
    reverse(str1.begin(),str1.begin()+2*(k+1));
    x++;
    reverse(a,a+x);
    reverse(b,b+x);
    rep(x) b[i]^=1;
    rep3(i,x-1,1){
        r[i]=k-r[i-1]-1;
    }
    r[0]=k;
    reverse(r,r+x);
}

void Merge(int x){
    bug(x);
    assert((a[x+1]==a[x]+1&&b[x]==0&&b[x+1]==0)||(a[x]==a[x+1]+1&&b[x]&&b[x+1]));
    r[x]=r[x+1],chkmin(a[x],a[x+1]),b[x]=b[x+1];
    rep2(i,x+1,m-1) r[i]=r[i+1],a[i]=a[i+1],b[i]=b[i+1];
    m--;
    int t=a[x];
    rep(m) if(a[i]>t) a[i]--;
}

void orzck(){
    cin >> str1 >> str2;
    n=sz(str1)/2;
    bug(n);
    rep(3) cnt1[i]=cnt2[i]=0;
    vector<int> vec[3];
    rep(n){
        int x=0,y=0;
        x=(str1[2*i]&1)+(str1[2*i+1]&1);
        y=(str2[2*i]&1)+(str2[2*i+1]&1);
        cnt1[x]++,cnt2[y]++;
        vec[y].pb(i);
    }
    rep(3) bug(vec[i]);
    rep(3) if(cnt1[i]!=cnt2[i]){
        print(-1);
        return;
    }
    res.clear();
    rep(n){
        int x=0;
        x+=(str1[2*i]&1)+(str1[2*i+1]&1);
        a[i]=vec[x].back();
        vec[x].pop_back();
        b[i]=str1[2*i]!=str2[2*a[i]];
        r[i]=i;
    }
    bug(n);
    m=n;
    while(m>1){
        bool ok=0;
        rep(m) pos[a[i]]=i;
        rep(m) bug(i,a[i]);
        rep(m) bug(i,b[i]);
        rep(m-1){
            int x=0,y=0;
            if(b[pos[i]]==0&&b[pos[i+1]]==1){
                bug(i,i+1);
                if(pos[i]<pos[i+1]){
                    op(pos[i+1]);
                    rep1(j,m) if(a[j]==i){
                        op(j-1);
                        break;
                    }
                }
                else{
                    op(pos[i]);
                    rep1(j,m) if(a[j]==i+1){
                        op(j-1);
                        break;
                    }
                }
                rep1(j,m) if(a[j]==i||a[j]==i+1){
                    Merge(j);
                    break;
                }
                ok=1;
                break;
            }
            if(b[pos[i]]&&b[pos[i+1]]&&pos[i]>pos[i+1]){
                bug(i,i+1);
                op(pos[i+1]);
                rep1(j,m) if(a[j]==i){
                    op(j-1);
                    break;
                }
                rep1(j,m) if(a[j]==i||a[j]==i+1){
                    Merge(j);
                    break;
                }
                ok=1;
                break;
            }
            if(b[pos[i]]==0&&b[pos[i+1]]==0&&pos[i]<pos[i+1]){
                bug(i,i+1);
                op(pos[i]);
                rep1(j,m) if(a[j]==i+1){
                    op(j-1);
                    break;
                }
                rep1(j,m) if(a[j]==i||a[j]==i+1){
                    Merge(j);
                    break;
                }
                ok=1;
                break;
            }
        }
        if(ok) continue;
        if(b[pos[m-1]]==0){
            op(pos[m-1]);
            op(m-1);
            m--;
        }
        else{
            op(m-2);
            rep(m-1) op(m-1),op(m-2);
            while(m>1) Merge(0);
        }
    }
    if(b[0]) op(0);
    bug(res);
    bug(str1,str2);
    assert(str1==str2);

    print(sz(res));
    for(auto i: res) print0(i);
    cout << "\n";
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