/*input
6
5 0
10 0
12 -4
10 -8
5 -8
3 -4
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
#define MAX 1515
#define INF 0x3f3f3f3f

int n;
long double x[MAX][2];
long double dis(int a , int b){
    long double tma = x[a][0] - x[b][0];
    long double tmb = x[a][1] - x[b][1];
    return sqrt(tma * tma + tmb * tmb);
}
long double query(int q , int w , int e){
    long double a = dis(q , w);
    long double b = dis(w , e);
    long double c = dis(e , q);
    long double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c)) / a;
}
int32_t main(){
    cin >> n;
    REP(i , 0 , n) REP(j , 0 , 2) cin >> x[i][j];
    long double ans = 1e30;
    REP(i , 0 , n) REP(j , 0 , n){
        int k = (j + 1) % n;
        if(k == i || i == j) continue;
        ans = min(ans , query(i , j , k));
    }
    printf("%.11Lf\n", ans);
    return 0;
}