#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

//#define int long long
#define ull unsigned long long
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
const int MOD=Mod2;
const int maxn=100005;
//i_am_noob
int n,a[maxn];
vector<vector<int>> res;
vector<int> vec,things[maxn];
vector<pii> things2[maxn];

void act(int x, int y, int z){
    if(x>y) swap(x,y);
    if(x>z) swap(x,z);
    if(y>z) swap(y,z);
    res.pb({x,y,z});
    a[x]^=1,a[y]^=1,a[z]^=1;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cin >> n;
    rep(n) cin >> a[i];
    if(n<=15){
        vector<int> basis,ori,comp;
        int target=0;
        rep(n) target^=a[i]*pow2(i);
        rep(n) rep2(j,i+1,n) rep2(k,j+1,n) if(j-i==k-j){
            int x=pow2(i)+pow2(j)+pow2(k),val=0;
            rep1(z,sz(basis)) if((x^basis[z])<x) x^=basis[z],val^=comp[z];
            if(x){
                basis.pb(x);
                ori.pb(pow2(i)+pow2(j)+pow2(k));
                comp.pb(val^pow2(sz(basis)-1));
            }
        }
        int val=0;
        rep(sz(basis)) if((target^basis[i])<target) target^=basis[i],val^=comp[i];
        if(target){
            print("NO");
            return 0;
        }
        print("YES");
        print(__builtin_popcountll(val));
        rep(sz(basis)) if(val&pow2(i)){
            rep1(j,n) if(ori[i]&pow2(j)) print0(j+1);
            cout << "\n";
        }
        return 0;
    }
    rep(n/3) if(a[3*i]&&a[3*i+1]&&a[3*i+2]) act(3*i,3*i+1,3*i+2);
    rep2(j,1,10) rep(n-2*j) if(a[i]&&a[i+j]&&a[i+2*j]) act(i,i+j,i+2*j);
    rep1(_,2){
        vec.clear();
        rep(n) if(a[i]&&i%2==_) vec.pb(i);
        rep(sz(vec)-1) things[vec[i+1]-vec[i]].pb(vec[i]);
        rep(n) if(!things[i].empty()){
            auto& v=things[i];
            vec.clear();
            rep1(j,sz(v)-1) if(v[j]+i==v[j+1]&&a[v[j]]&&a[v[j]+i]&&a[v[j]+2*i]) act(v[j],v[j]+i,v[j]+2*i);
            rep1(j,sz(v)-1) if(a[v[j]]&&a[v[j]+i]) vec.pb(v[j]);
            v=vec;
            rep1(j,sz(v)>>1) act(v[j*2],(v[j*2]+v[j*2+1]+i)/2,v[j*2+1]+i),act(v[j*2]+i,(v[j*2]+v[j*2+1]+i)/2,v[j*2+1]);
            v.clear();
        }
    }
    vec.clear();
    rep(n) if(a[i]) vec.pb(i);
    rep(sz(vec)) rep2(j,i+1,sz(vec)){
        if(vec[i]*2-vec[j]>=0){
            if(a[vec[i]*2-vec[j]]&&a[vec[i]]&&a[vec[j]]) act(vec[i]*2-vec[j],vec[i],vec[j]);
            else things2[vec[i]*2-vec[j]].pb({vec[i],vec[j]});
        }
        if((vec[i]+vec[j])%2==0){
            if(a[vec[i]+vec[j]>>1]&&a[vec[i]]&&a[vec[j]]) act(vec[i]+vec[j]>>1,vec[i],vec[j]);
            else things2[vec[i]+vec[j]>>1].pb({vec[i],vec[j]});
        }
        if(vec[j]*2-vec[i]<n){
            if(a[vec[j]*2-vec[i]]&&a[vec[i]]&&a[vec[j]]) act(vec[j]*2-vec[i],vec[i],vec[j]);
            else things2[vec[j]*2-vec[i]].pb({vec[i],vec[j]});
        }
    }
    rep(n) if(!things2[i].empty()){
        auto& v=things2[i];
        vector<pii> vec1;
        for(auto& [x,y]: v) if(a[x]&&a[y]) vec1.pb({x,y});
        v=vec1;
        rep1(j,sz(v)>>1) if(sz(set<int>({v[j*2].first,v[j*2].second,v[j*2+1].first,v[j*2+1].second}))==4&&a[v[j*2].first]&&a[v[j*2].second]&&a[v[j*2+1].first]&&a[v[j*2+1].second]) act(i,v[j*2].first,v[j*2].second),act(i,v[j*2+1].first,v[j*2+1].second); 
    }
    set<int> st;
    rep(n) if(a[i]) st.insert(i);
    while(sz(st)>=3){
        auto it1=st.begin(),it2=next(it1),it3=next(it2);
        int x=*it1,y=*it2,z=*it3;
        if(y-x==z-y){
            act(x,y,z);
            rep(3) st.erase(st.begin());
        }
        else if(y-x<z-y){
            act(x,y,2*y-x);
            st.erase(x),st.erase(y);
            st.insert(2*y-x);
        }
        else{
            act(2*y-z,y,z);
            st.erase(y),st.erase(z);
            st.insert(2*y-z);
        }
    }
    while(sz(st)){
        int x=*st.begin();
        if(x>=7){
            act(x-6,x-5,x-4),act(x-5,x-4,x-3),act(x-6,x-3,x);
        }
        else{
            act(x+3,x+4,x+5),act(x+4,x+5,x+6),act(x,x+3,x+6);
        }
        st.erase(st.begin());
    }
    print("YES");
    print(sz(res));
    for(auto& vec: res){
        for(auto i: vec) print0(i+1);
        cout << "\n";
    }
    return 0;
}