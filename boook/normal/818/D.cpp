/*input
3 10
1 2 3
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , ok[MAX] , cnt[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , 1000000 + 1) ok[i] = 1;
    ok[m] = 0;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1){
        if(ok[x[i]] == -1) continue;
        else if(cnt[x[i]] < cnt[m]) ok[x[i]] = -1;
        else cnt[x[i]] ++;
    }
    REP(i , 1 , 1000000 + 1){
        if(ok[i] == 1 && cnt[i] >= cnt[m]){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}