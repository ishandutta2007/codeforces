/*input
4
-10000000 1
10000000 1
-10000000 10000000
10000000 10000000
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
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f
#define PII pair<double , double>

int n;
PII x[MAX]; 
inline int rit(){
    int res = 0;
    int val = 1;
    char c = getchar();
    while(!isdigit(c)){
        val = c == '-' ? -1 : val;
        c = getchar();
    }
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res * val;
}
int32_t main(){
    n = rit();
    int v1 = 0 , v2 = 0;
    REP(i , 1 , n + 1) x[i].A = rit() , x[i].B = rit();

    REP(i , 1 , n + 1) if(x[i].B > 0) v1 = 1;
    REP(i , 1 , n + 1) if(x[i].B < 0) v2 = 1;
    REP(i , 1 , n + 1) x[i].B = abs(x[i].B);


    if(v1 && v2) return cout << -1 << endl , 0;
    else {
        double l = 0 , r = 5e13 + 10;
        REP(times , 0 , 400){
            double mid = (l + r) / 2;
            double ql = -1e10 , qr = 1e10;
            int ok = 1;
            REP(i , 1 , n + 1){
                double h = x[i].B - mid;
                if(h < 0) h = -h;
                if(h > mid){
                    ok = 0;
                    break;
                }
                double r = sqrt((long double)(mid * mid - h * h));
                ql = max(ql , x[i].A - r);
                qr = min(qr , x[i].A + r);
            }
            if(ql <= qr && ok == 1)
                 r = mid;
            else l = mid;
        }
        printf("%.11Lf\n", (long double)l);
    }
    return 0;
}