/*input
3 2
1 2 3
2 3 1
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
#define MAX 100900
#define INF 0x3f3f3f3f


int h[15][MAX] , g[MAX] , n , m;
int mod , M[] = {1000000007LL , 1000000009LL};
int query(int i , int l , int r){
    int tmp = (h[i][l - 1] * g[r - l + 1]) % mod;
    return (h[i][r] + mod - tmp) % mod;
}
int x[15][MAX] , r[15][MAX];
int32_t main(){
    IOS;
    srand(time(NULL)) , mod = M[rand() % 2];
    cin >> n >> m;
    REP(i , 1 , m + 1) REP(j , 1 , n + 1) cin >> x[i][j];

    int AC = rand() % 100 * 3 + 31;
    g[0] = 1;
    REP(i , 1 , n + 1) g[i] = g[i - 1] * AC % mod;
    REP(i , 1 , m + 1) REP(j , 1 , n + 1) h[i][j] = (h[i][j - 1] * AC + x[i][j] * 2) % mod;

    REP(i , 1 , m + 1) REP(j , 1 , n + 1) r[i][x[i][j]] = j;
    int ans = 0;
    REP(i , 1 , n + 1){
        int now = i;
        RREP(j , 20 , 0){
            int to = (now + (1 << j)) , len = to - i + 1;
            if(to <= n){
                int same = query(1 , i , to) , ok = 1;
                REP(k , 2 , m + 1){
                    if(query(k , r[k][x[1][i]] , r[k][x[1][i]] + len - 1) != same){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1) now = to;
            }
        }
        ans += now - i + 1;
    }
    cout << ans << endl;
    return 0;
}