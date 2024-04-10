#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 400000
#define INF 0x3f3f3f3f

int n , m;
vector<int> v[MAX] , o[MAX];
int dp[MAX];
int DFS(int now){
    if(dp[now] != -1) return dp[now];
    int tmp = 1;
    for(auto to : v[now]){
        tmp = max(tmp , DFS(to) + 1);
    }
    return dp[now] = tmp;
}
int32_t main(){
    MEM(dp , -1);
    cin >> n >> m;
    REP(i , 0 , m){
        int q , w;
        cin >> q >> w;
        o[q].pb(w) , o[w].pb(q);
        v[max(q , w)].pb(min(q , w));
    }
    int ans = 0;
    REP(i , 1 , n + 1){
        int len = DFS(i);
        ans = max(ans , len * (int)(o[i].size()));
    }
    cout << ans << endl;
    return 0;
}