#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , pre[MAX] , use[MAX];
vector<PII> v[MAX];
vector<int> base;
void update(int val){
    for(auto to : base)
        val = min(val , to ^ val);
    if(val) base.pb(val);
}
void DFS(int now , int val){
    pre[now] = val;
    use[now] = 1;
    for(auto to : v[now]){
        if(use[to.A]) update(pre[to.A] ^ val ^ to.B);
        else DFS(to.A , val ^ to.B);
    }
}
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , m){
        int q , w , e;
        cin >> q >> w >> e;
        v[q].pb(mp(w , e));
        v[w].pb(mp(q , e));
    }
    DFS(1 , 0);
    int ans = pre[n];
    for(auto to : base)
        ans = min(ans , ans ^ to);
    cout << ans << endl;
    return 0;
}