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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m;
double ppow(double a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a , k >> 1);
    if(k % 2 == 1) return ppow(a * a , k >> 1) * a;
}
double c[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) c[i] = ppow((double)i / (double)n,  m);
    double sum = 0;
    REP(i , 1 , n + 1){
        sum = sum + ((c[i] - c[i - 1]) * i);
    }
    printf("%.011f\n", sum);
    return 0;
}