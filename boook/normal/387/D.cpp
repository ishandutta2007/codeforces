#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 510
#define INF 0x3f3f3f3f

int n , m , o[MAX] , no;
int use[MAX] , good[MAX];
VI v[MAX];
int DFS(int now){
    // DBGG("DFS now = " , now);
    if(now == no) return 0;
    for(auto to : v[now]){
        if(use[to] || to == no) continue;
        use[to] = 1;
        if(good[to] == -1 || DFS(good[to]) == 1){
            good[to] = now;
            return 1;
        }
    }
    return 0;
}
int Match(int now){
    int cnt = 0;
    MEM(good , -1);
    no = now;
    REPNM(i , 1 , n + 1){
        MEM(use , 0);
        cnt += DFS(i);
    }
    return cnt;
}
int solve(int now){
    int tmp = (n - 1) * 2 + 1 - o[now];
    int others = m - o[now] , need = n - 1;
    int match = Match(now);
    // int match = 0;
    // DBGG("57 = " , tmp + others - match + need - match);
    return tmp + others - match + need - match;
}
int32_t main(){
    cin >> n >> m;
    REPNM(i , 1 , m + 1){
        int q , w;
        cin >> q >> w;
        if(q == w) o[q] ++ , v[q].pb(w);
        else o[q] ++ , o[w] ++ , v[q].pb(w);
    }
    int ans = INF;
    REPNM(i , 1 , n + 1){
        // DBGG("now i = " , i);
        ans = min(ans , solve(i));
    }
    cout << ans << endl;
    return 0;
}