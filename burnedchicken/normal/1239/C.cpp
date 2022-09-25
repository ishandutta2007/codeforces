#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

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

const int maxn=100005;

//i_am_noob
//#define wiwihorz  
int n,k,a[maxn],cur,res[maxn];
vector<pii> vec;
priority_queue<int,vector<int>,greater<int>> pq;
queue<int> q;
set<int> inq;

void orzck(){
    cin >> n >> k;
    rep(n) cin >> a[i];
    rep(n) vec.pb({a[i],i});
    sort(all(vec)),reverse(all(vec));
    int cur=-1;
    while((!q.empty())||(!vec.empty())||!pq.empty()){
        int de;
        if(q.empty()) de=1;
        else if(vec.empty()) de=2;
        else if(vec.back().first<=cur+k) de=1;
        else de=2;
        if(de==1){
            int t=vec.back().first;
            pq.push(vec.back().second);
            vec.pop_back();
            if(q.empty()||pq.top()<*inq.begin()){
                if(q.empty()) cur=t;
                q.push(pq.top());
                inq.insert(pq.top());
                pq.pop();
            }
        }
        else{
            int t=cur+k;
            res[q.front()]=t;
            inq.erase(q.front());
            q.pop();
            if(!pq.empty()) if(q.empty()||pq.top()<*inq.begin()){
                q.push(pq.top());
                inq.insert(pq.top());
                pq.pop();
            }
            cur=t;
        }
    }
    rep(n) print0(res[i]);
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}