//  228

/*  
    Author - Deepak Barnwal;
*/ 
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
typedef long double ld;
typedef pair<int,int> pii;
#define all(V) V.begin(),V.end()
#define allr(V) V.rbegin(),V.rend()
#define endl "\n"
#define precision(n) fixed<<setprecision(n)
#define NewLine cout<<endl; 
#define sz(V) (int)(V.size())
#define rep(i,a,b) for(i=a; i<b; i++)
const int Infinity = (int)(1e18);
const ld pi =  3.1415926535897932384626433;
const int MOD = (int)(1e9+7);
int     dx []    =  {-1 , 0 , 1 , 0 ,-1,-1, 1,  1};
int     dy []    =  { 0 , 1 , 0 ,-1 ,-1, 1, 1, -1};
char    dir[]    =  {'U','R','D','L'};
void OJ();
void TIME_IT();
template<typename...T>void read(T &...args) {((cin >> args), ...);}
template<typename...T>void print(T &&...args) {((cout<< args <<" "), ...);}
// -----------------------------------------------------------------------.
const int maxn = (int)(1e6+5);

/*
    Dijkstra.
*/
vector<pii> adj[maxn];
int dis[maxn] ;
void dijkstra(int start){
    memset(dis,0x3f,sizeof(dis));
    dis[start] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0 , start});
    while(!pq.empty()){
        int cur = pq.top().second , dis_cur = pq.top().first;
        pq.pop();
        if(dis_cur > dis[cur])
            continue;
        for(auto it:adj[cur]){
            int x = it.first , len = it.second;
            if(dis[x] > dis[cur] + len){
                dis[x] = dis[cur] + len;
                pq.push({dis[x] , x});
            }
        }
    }
}
void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
#define debug(x...)
#endif

void solve(int TC){
    int n,i,m,s,l;
    read(n , m , s);
    vector<array<int,3>> edges;
    rep(i,0,m){
        int a,b,c;read(a,b,c);
        adj[a].push_back({b , c});
        adj[b].push_back({a , c});
        edges.push_back({a,b,c});
    }
    read(l);
    dijkstra(s);
    int ans = 0;
    rep(i,1,n+1){
        ans += (dis[i] == l);
    }
    map<pair<int,int> , int> mpp;
    for(auto it:edges){
        int a = it[0] ,b = it[1] , c = it[2];
        int d1 = dis[a] + it[2];
        int d2 = dis[b] + it[2];
        // both
        if(d1 > l && d2 > l && dis[a] < l && dis[b] < l && ((c + dis[a] + dis[b] ) > 2ll*l))
            ans += 2;
        else
        // only one point from a;
        if(d1 > l && dis[a] < l && ((c - (l - dis[a])) + dis[b]  >= l) ){
            ans++;
        }else
        // only one point from b;
        if(d2 > l && dis[b] < l && ((c - (l - dis[b])) + dis[a]  >= l) ){
            ans++;
        }
        debug(a,b,c ,dis[a], dis[b] , d1 ,d2, ans);
    }
    print(ans);
}
signed main(){
    FastIO;
    OJ();
    int Test = 1;
    // cin>>Test;
    for(int i=1; i<=Test; i++){
        solve(i);
    }
    TIME_IT();
    return 0;
}
void OJ(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "wb", stdout);
    #endif
}
void TIME_IT(){
    #ifndef ONLINE_JUDGE
        cerr<<"\nTime Elapsed: " <<precision(10)<< 1.0*clock() / CLOCKS_PER_SEC << " sec";
    #endif
}