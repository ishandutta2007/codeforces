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
const int maxn=300005;

//i_am_noob
#define wiwihorz  

int val[maxn*4],tag[maxn*4];

void pull(int x){val[x]=val[x<<1]+val[x<<1|1];}
void push(int k, int l, int r){
    int mid=l+r>>1;
    if(l!=r&&tag[k]!=-1){
        tag[k<<1]=tag[k],tag[k<<1|1]=tag[k];
        val[k<<1]=(mid-l+1)*tag[k],val[k<<1|1]=(r-mid)*tag[k];
    }
    tag[k]=-1;
}
void modify(int k, int l, int r, int ql, int qr, int x){
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r){
        tag[k]=x,val[k]=(r-l+1)*x;
        return;
    }
    push(k,l,r);
    int mid=l+r>>1;
    modify(k<<1,l,mid,ql,qr,x),modify(k<<1|1,mid+1,r,ql,qr,x);
    pull(k);
}
int query(int k, int l, int r, int ql, int qr){
    if(ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return val[k];
    push(k,l,r);
    int mid=l+r>>1;
    return query(k<<1,l,mid,ql,qr)+query(k<<1|1,mid+1,r,ql,qr);
}

int n,m,l[maxn],r[maxn];
string str1,str2;

void orzck(){
    cin >> n >> m >> str1 >> str2;
    rep(4*n+5) val[i]=0,tag[i]=-1;
    rep(n) if(str2[i]=='1') modify(1,0,n-1,i,i,1);
    rep(m) cin >> l[i] >> r[i];
    rep(m) l[i]--,r[i]--;
    reverse(l,l+m),reverse(r,r+m);
    bug("de");
    rep(m){
        int cnt=query(1,0,n-1,l[i],r[i]);
        if(cnt<=(r[i]-l[i])/2) modify(1,0,n-1,l[i],r[i],0);
        else if((r[i]-l[i]+1-cnt)<=(r[i]-l[i])/2) modify(1,0,n-1,l[i],r[i],1);
        else{
            print("NO");
            return;
        }
    }
    bug("de2");
    rep(n) if(query(1,0,n-1,i,i)!=str1[i]-'0'){
        bug(i,query(1,0,n-1,i,i));
        print("NO");
        return;
    }
    print("YES");
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