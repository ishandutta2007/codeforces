//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <bitset>
#include <deque>
#include <stack>
#include <array>
#include <cassert>
#include <iomanip>
#include <unordered_map>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ALL(x) x.begin(), x.end()
#define vi vector<int>
#define CASE int t;cin>>t;for(int ca=1;ca<=t;ca++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
#define int long long
const int MAX = 1 << 20, MOD = 1e9 + 7;
ll dn, mn[MAX], vis[MAX], N, lt[MAX], v[MAX], t, a[51][51];
vi edge[MAX];
 
struct DATA{
    int to, c, v;
    DATA(int _to = 0, int _c = 0, int _v = 0) : to(_to), c(_c), v(_v) {}
}e[MAX];
 
void add(int u, int to, int c, int v){
//    cout << u << " " << to << " " << c << " " << v << '\n';
    edge[u].PB(dn);
    e[dn++] = DATA(to, c, v);
    edge[to].PB(dn);
    e[dn++] = DATA(u, 0, -v);
}
 
ll flow(){
    for(int i = 0;i <= N;i++){
        vis[i] = 0;
        mn[i] = 2e18;
    }
    queue<int> q;
    q.push(0);
    mn[0] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for(int i : edge[now]){
            if(e[i].c > 0 && mn[now] + e[i].v < mn[e[i].to]){
                mn[e[i].to] = mn[now] + e[i].v;
                lt[e[i].to] = i;
                if(!vis[e[i].to]){
                    vis[e[i].to] = 1;
                    q.push(e[i].to);
                }
            }
        }
    }
    if(mn[N] == 2e18)
        return 2e18;
    int now = N;
    while(now){
        e[lt[now]].c--;
        e[lt[now] ^ 1].c++;
        now = e[lt[now] ^ 1].to;
//        cout << now << " ";
    }
//    cout << '\n';
    return mn[N];
}

int dfs(int now, int mn){
    if(v[now] == t)
        return 0;
    v[now] = t;
    if(now == N)
        return mn;
    for(int i : edge[now]){
        if(!e[i].c)
            continue;
        int v = dfs(e[i].to, min(mn, e[i].c));
        if(v){
            e[i].c -= v;
            e[i ^ 1].c += v;
            return v;
        }
    }
    return 0;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    N = n + 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
            if(a[i][j]){
                add(i, j, a[i][j], 0);
            }
        }
    }
    add(0, 1, 2e9, 0);
    add(n, N, 2e9, 0);
    int ans = 0;
    t = 1;
    while(int v = dfs(0, 2e9)){
        ans += v;
//        cout << v << '\n';
        t++;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(a[i][j]){
                add(i, j, 2e9, 1);
            }
        }
    }
    while(k>0){
        k -= flow();
        if(k >= 0)
            ans++;
    }
    cout << ans << '\n';
}
 
signed main(){
    IOS
//    CASE{
//        cout << "Case #" << ca << ": ";
        solve();
//    }
    return 0;
}