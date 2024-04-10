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
#define MAX 300000
#define INF 0x3f3f3f3f

int n;
vector<int> v[MAX];
PII dp[MAX];
PII DFS(int now , int fa , int made , int choose){
    if(dp[now].A != -1) return dp[now];
    if(v[now].size() == 1 && v[now][0] == fa){
        return dp[now] = mp(1 , 1);
    }
    // DBGG("now = " , now);
    int sum = 0 , cnt = 0;
    if(choose != made) cnt = 0;
    else cnt = INF;
    for(auto to : v[now]){
        if(to == fa) continue;
            sum += DFS(to , now , made , 1 - choose).B;
        if(choose != made)
            cnt += DFS(to , now , made , 1 - choose).A;
        else cnt = min(cnt , DFS(to , now , made , 1 - choose).A);
    }
    // DB4("now = " , now , cnt , sum);
    return dp[now] = mp(cnt , sum);
}
int32_t main(){
    cin >> n;
    REP(i , 0 , n - 1){
        int q , w;
        cin >> q >> w;
        v[q].pb(w);
        v[w].pb(q);
    }
    if(n == 1){
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    REP(i , 0 , n + 1) dp[i] = mp(-1 , -1);
    PII tma = DFS(1 , -1 , 0 , 0);
    REP(i , 0 , n + 1) dp[i] = mp(-1 , -1);
    PII tmb = DFS(1 , -1 , 1 , 0);
    cout << tma.B - tma.A + 1 << " " << tmb.A << endl;
    return 0;
}