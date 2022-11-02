/*input
5 3
-1 3
2 4
1 1
3 5
2 2
1 4
2 3
3 5
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
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , x[MAX][2] , ans[MAX] , p[MAX][2];
PII v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
    REP(i , 1 , m + 1){
        int a , b; cin >> a >> b;
        ans[a] -= min(x[a][0] + x[b][1] , x[a][1] + x[b][0]);
        ans[b] -= min(x[a][0] + x[b][1] , x[a][1] + x[b][0]);
    }
    REP(i , 1 , n + 1) ans[i] -= x[i][0] + x[i][1];


    REP(i , 1 , n + 1) v[i] = mp(x[i][1] - x[i][0] , i);
    sort(v + 1 , v + 1 + n);


    REP(i , 1 , n + 1) p[i][0] = p[i - 1][0] + x[v[i].B][0];
    REP(i , 1 , n + 1) p[i][1] = p[i - 1][1] + x[v[i].B][1];

    // REP(i , 1 , n + 1) cout << v[i].B << " "; cout << endl;
    // REP(i , 1 , n + 1) cout << p[i][0] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << p[i][1] << " " ; cout << endl;

    REP(i , 1 , n + 1){
        int val = x[i][1] - x[i][0];
        int now = 1;
        RREP(j , 20 , 0){
            int to = now + (1 << j);
            if(to <= n && v[to].A <= val) now = to;
        }
        // DBGG("now = " , now);
        int las = n - now;
        ans[i] += x[i][0] * now + (p[now][1] - p[0][1]);
        ans[i] += x[i][1] * las + (p[n][0] - p[now][0]);
    }
    REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}