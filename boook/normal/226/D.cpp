/*input
2 4
-1 -1 -1 2
1 1 1 1
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 110
#define INF 0x3f3f3f3f

int n , m , x[MAX][MAX];
int v1[MAX] , v2[MAX] , r1[MAX] , r2[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> x[i][j];
    
    int sum = 0;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1){
        v1[i] += x[i][j];
        v2[j] += x[i][j];
        sum += x[i][j];
    }

    while(1){
        int ok = 0;
        REP(i , 1 , n + 1){
            if(v1[i] < 0){
                v1[i] *= -1;
                r1[i] ^= 1;
                sum += v1[i] * 2;
                REP(j , 1 , m + 1) v2[j] -= x[i][j];
                REP(j , 1 , m + 1) x[i][j] *= -1;
                REP(j , 1 , m + 1) v2[j] += x[i][j];
                ok = 1;
            }
        }
        REP(j , 1 , m + 1){
            if(v2[j] < 0){
                v2[j] *= -1;
                r2[j] ^= 1;
                sum += v2[j] * 2;
                REP(i , 1 , n + 1) v1[i] -= x[i][j];
                REP(i , 1 , n + 1) x[i][j] *= -1;
                REP(i , 1 , n + 1) v1[i] += x[i][j];
                ok = 1;
            }
        }
        if(ok == 0) break;
    }
    vector<int> p1 , p2;
    REP(i , 1 , n + 1) if(r1[i]) p1.pb(i);
    REP(i , 1 , m + 1) if(r2[i]) p2.pb(i);
    cout << p1.size() << " ";
    for(auto to : p1) cout << to << " " ; cout << endl;
    cout << p2.size() << " ";
    for(auto to : p2) cout << to << " " ; cout << endl;
    // cout << sum << endl;
    return 0;
}