/*input
5
8 7 4 8 3
4 2 5 3 7
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
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , sol[MAX];
int32_t main(){
    srand(time(NULL));
    IOS;
    cin >> n;
    int v1 = 0 , v2 = 0;
    REP(i , 1 , n + 1) cin >> a[i] , v1 += a[i];
    REP(i , 1 , n + 1) cin >> b[i] , v2 += b[i];
    REP(i , 1 , n + 1) sol[i] = i;
    int m = n / 2 + 1;
    while(1){
        random_shuffle(sol + 1 , sol + 1 + n);
        int x1 = 0 , x2 = 0;
        REP(i , 1 , m + 1){
            x1 += a[sol[i]];
            x2 += b[sol[i]];
        }
        if(x1 * 2 > v1 and x2 * 2 > v2){
            cout << m << endl;
            REP(i , 1 , m + 1) cout << sol[i] << " " ; cout << endl;
            return 0;
        }
    }
    return 0;
}