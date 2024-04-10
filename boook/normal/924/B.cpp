/*input
3 1
2 5 10
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int int_fast64_t
#define MAX 100900
#define INF 0x3f3f3f3f

int n , k , x[MAX];
int32_t main(){
    cin >> n >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    double ans = -1;
    int ok = 0;
    REP(i , 1 , n + 1){
        int now = i;
        RREP(j , 20 , 0){
            int to = now + (1 << j);
            if(to <= n && x[to] - x[i] <= k) now = to;
        }
        if(now > i + 1){
            ok = 1;
            ans = max(ans , ((double)x[now] - x[i + 1]) / (x[now] - x[i]));
        }
    }
    if(ok == 0) cout << -1 << endl;
    else  printf("%.11f\n", ans);
    return 0;
}