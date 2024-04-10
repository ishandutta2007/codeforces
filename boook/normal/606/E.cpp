#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200000
#define INF 0x3f3f3f3f

double p , q;
int n;
double x[MAX][2];
double judge(double a){
    double b = 1e100;
    REP(i , 0 , n) b = min(b , (1 - x[i][0] * a) / x[i][1]);
    return a * p + b * q;
}
int32_t main(){
    IOS;
    cin >> n >> p >> q;
    REP(i , 0 , n) REP(j , 0 , 2) cin >> x[i][j];
    double l = 0 , r = 1e100;
    REP(i , 0 , n) r = min(r , 1.0 / x[i][0]);
    REP(times , 0 , 500){
        double lx = (l + (r - l) / 3.0) , rx = (r - (r - l) / 3.0);
        if(judge(lx) < judge(rx)) l = lx;
        else r = rx;
    }
    printf("%.15lf\n" , judge(l));
    return 0;
}