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

long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;
int n;
long double x[MAX][2];
long double sml , big;
long double dis(int a , int b){
    long double tma = (x[a][0] - x[b][0]);
    long double tmb = (x[a][1] - x[b][1]);
    return tma * tma + tmb * tmb;
}
long double P(int a , int b , long double xx){
    long double tmp = (x[a][0] - xx) * (x[a][1] - x[b][1]) / (x[a][0] - x[b][0]);
    return -(tmp - x[a][1]);
}
long double dd(long double a , long double b){
    return a * a + b * b;
} 
long double DIS(int a , int b){
    if(x[a][0] * x[b][1] == x[b][0] * x[a][1]) return big;
    int ook = 0;
    if(x[a][0] - x[b][0] < 0.00000001){
        ook = 1;
        swap(x[a][0] , x[a][1]);
        swap(x[b][0] , x[b][1]);
    }
    if(x[a][0] > x[b][0]) swap(a , b);
    long double ll = x[a][0] , rr = x[b][0];
    RREP(times , 200 , 0){
        long double tma = (ll + (rr - ll) / 3.0);
        long double tmb = (rr - (rr - ll) / 3.0);
        if(dd(tma , P(a , b , tma)) > dd(tmb , P(a , b , tmb))) ll = tma;
        else rr = tmb;
    }
    long double ttans = dd(ll , P(a , b , ll));
    if(ook){
        swap(x[a][0] , x[a][1]);
        swap(x[b][0] , x[b][1]);
    }
    return ttans;
}
int32_t main(){
    cin >> n >> x[0][0] >> x[0][1];
    REP(i , 1 , n + 1){
        cin >> x[i][0] >> x[i][1];
    }
    sml = dis(0 , 1) , big = dis(0 , 1);
    REP(i , 2 , n + 1){
        sml = fmin(sml , dis(0 , i));
        big = fmax(big , dis(0 , i));
    }
    REP(i , 1 , n + 1) x[i][0] -= x[0][0] , x[i][1] -= x[0][1];
    REP(i , 2 , n + 1){
        sml = fmin(sml , DIS(i , i - 1));
    }
    sml = fmin(sml , DIS(n , 1));

    // DB4("sml = " , sml , "big = " , big);
    double tmp = (big - sml) * pi;
    printf("%.011f\n", tmp);
    return 0;
}