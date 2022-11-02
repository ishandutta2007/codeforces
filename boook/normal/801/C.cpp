/*input
3 5
4 3
5 2
6 1
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

int n , m , a[MAX] , b[MAX];

int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> a[i] >> b[i];
    int sum = 0;
    REP(i , 1 , n + 1) sum += a[i];
    if(sum <= m) return cout << "-1" << endl , 0;
    double l = 0 , r = 1e15;
    REP(times , 0 , 100){
        double mid = (l + r) / 2;
        double need = 0;
        REP(i , 1 , n + 1){
            double tmp = mid * a[i] - (double)b[i];
            if(tmp > 0) need += tmp;
        }
        if(need <= mid * m) l = mid;
        else r = mid;
    }
    printf("%.11f\n", r);
    return 0;
}