/*input
4
0 0 0
0 10 0
10 10 0
10 0 0
0 0 0
4 1
0 10 0
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
#define int long long
#define double long double
#define PII  pair<int , int>
#define PIII pair<int , PII>
#define PDD  pair<double , double>
#define PDDD pair<double , PDD>
#define eps 1e-9
#define MAX 10900
#define INF 0x3f3f3f3f

PDD operator + (PDD x , PDD y){ return mp(x.A + y.A , x.B + y.B); }
PDD operator - (PDD x , PDD y){ return mp(x.A - y.A , x.B - y.B); }
PDDD operator + (PDDD x , PDDD y){ return mp(x.A + y.A , x.B + y.B); }
PDDD operator - (PDDD x , PDDD y){ return mp(x.A - y.A , x.B - y.B); }
PDDD operator * (PDDD x , double y){ return mp(x.A * y , mp(x.B.A * y , x.B.B * y)); }

double calcDis(PDDD now){
    double v1 = now.A;
    double v2 = now.B.A;
    double v3 = now.B.B;
    return sqrt(v1 * v1 + v2 * v2 + v3 * v3);
}
PDDD x[MAX] , s;
double v1 , v2 , pre[MAX] , dis[MAX];
int n;
int32_t main(){

    cin >> n , n ++;
    REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B.A >> x[i].B.B;
    cin >> v1 >> v2;
    cin >> s.A >> s.B.A >> s.B.B;
    REP(i , 2 , n + 1) pre[i] = pre[i - 1] + calcDis(x[i] - x[i - 1]) * v1;
    REP(i , 1 , n + 1) dis[i] = calcDis(x[i] - s) * v2;

    // REP(i , 1 , n + 1) cout << pre[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << dis[i] << " " ; cout << endl;

    if(dis[n] > pre[n] + eps) return cout << "NO" << endl , 0;
    else if(dis[1] <= pre[1] + eps){
        cout << "YES" << endl;
        cout << "0" << endl;
        cout << s.A << " " << s.B.A << " " << s.B.B << endl;        
    }
    else {
        REP(i , 1 , n + 1) if(dis[i] + eps >= pre[i] && dis[i + 1] <= pre[i + 1] + eps){
            cout << "YES" << endl;
            double l = 0.0 , r = 1.0;
            PDDD dir = x[i + 1] - x[i] , base = x[i];
            double predis = pre[i] , nowdis , smldis;
            PDDD now;
            REP(times , 0 , 120){
                double mid = (l + r) / 2;
                now = base + dir * mid;
                nowdis = predis + calcDis(dir * mid) * v1;
                smldis = calcDis(now - s) * v2;
                if(smldis <= nowdis) r = mid;
                else l = mid;
            }
            printf("%.11Lf\n" , calcDis(now - s) / v1);
            printf("%.11Lf %.11Lf %.11Lf\n" , now.A , now.B.A , now.B.B);
            return 0;
        }
    }
    return 0;
}