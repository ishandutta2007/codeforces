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
#define MAX 
#define INF 0x3f3f3f3f

double a , b , c , d , e , f;
pair<double , double> now , pre;
double sum = 0;
void ADD(pair<double , double> q , pair<double , double> w){
    // DB4(q.A , q.B , w.A , w.B);
    sum += q.A * w.B - q.B * w.A;
}
int32_t main(){
    cin >> a >> b >> c >> d >> e >> f;
    double tmp = sqrt(3);
    now = mp(0.0 , 0.0) , pre = mp(1.0 * a , 0.0 * a) , ADD(now , pre);
    now = pre , pre = mp(now.A + 0.5 * b , now.B + tmp * b) , ADD(now , pre);
    now = pre , pre = mp(now.A - 0.5 * c , now.B + tmp * c) , ADD(now , pre);
    now = pre , pre = mp(now.A - 1.0 * d , now.B + 0.0 * d) , ADD(now , pre);
    now = pre , pre = mp(now.A - 0.5 * e , now.B - tmp * e) , ADD(now , pre);
    now = pre , pre = mp(now.A + 0.5 * f , now.B - tmp * f) , ADD(now , pre);
    // printf("%.11f\n", sum / tmp);
    printf("%d\n", (int)(sum / tmp + 0.5));
    return 0;
}