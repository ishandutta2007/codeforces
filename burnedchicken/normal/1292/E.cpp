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
int n;
string res;

vector<int> query(string str){
    print("?",str);
    cout << flush;
    int x;
    vector<int> vec;
    cin >> x;
    vec.resize(x);
    rep(x){
        cin >> vec[i];
        vec[i]--;
        rep2(j,vec[i],vec[i]+sz(str)) res[j]=str[j-vec[i]];
    }
    return vec;
}

void report(string str=res){
    print("!",str);
    cout << flush;
    int x;
    cin >> x;
}

void brute(){
    int x=count(all(res),' ');
    vector<int> vec;
    rep(n) if(res[i]==' ') vec.pb(i);
    int val[4]={2,2,2,3};
    int k=1;
    for(auto i: vec) k*=val[i];
    rep(k){
        int cnt=0;
        rep1(j,x){
            int tmp=i%val[vec[j]];
            if(j) tmp=i/2;
            if(tmp==0) res[vec[j]]='O';
            else if(tmp==1) res[vec[j]]='H';
            else res[vec[j]]='C';
        }
        if(i==k-1||sz(query(res))){
            report();
            return;
        }
    }
}

void orzck(){
    cin >> n;
    res.resize(n);
    rep(n) res[i]=' ';
    query("CC"),query("CH"),query("CO");
    if(n==4){
        if(count(all(res),' ')<=2){
            brute();
            return;
        }
        if(sz(query("HO"))){
            brute();
            return;
        }
        if(sz(query("OOO"))){
            if(!count(all(res),' ')){
                report();
                return;
            }
            if(sz(query("OOOH"))){
                report();
                return;
            }
            report("OOOC");
            return;
        }
        query("OOH"),query("OHH");
        if(res[0]==' ') res[0]=res[1]=res[2]='H';
        res[3]='H';
        if(sz(query(res))) report();
        else{
            res[3]='C';
            report();
        }
        return;
    }
    query("HO"),query("OH");
    rep(n-2){
        if(res[i]=='H'&&res[i+1]==' ') res[i+1]='H';
        if(res[i]=='O'&&res[i+1]==' ') res[i+1]='O';
    }
    int x=0;
    rep(n-1) if(res[i]==' ') x++;
    string tmp;
    rep(n-1) tmp+=(res[i]==' '?'H':res[i]);
    if(sz(query(tmp))){
        rep(n-1) if(res[i]==' ') res[i]='H';
    }
    else{
        rep(n-1) if(res[i]==' ') res[i]='O';
    }
    if(!count(all(res),' ')){
        report();
        return;
    }
    res[n-1]='C';
    if(sz(query(res))) report();
    else{
        res[n-1]=res[n-2];
        report();
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    //freopen("input1.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    //freopen("output2.txt","w",stderr);
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