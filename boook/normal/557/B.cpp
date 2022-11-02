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
#define int long long
#define MAX 900000
#define INF 0x3f3f3f3f

int n , m;
int x[MAX];

int32_t main(){
    cin >> n >> m;
    m *= 10;
    REP(i , 0 , n + n) cin >> x[i] , x[i] *= 10;
    sort(x , x + n + n);
    int a = x[0];
    int b = x[n] , ans = 0;
    if(b >= a * 2) ans = a * n * 3;
    else ans = b * n + (b / 2) * n;
    double tt = min(ans , m);
    tt /= 10.0;
    printf("%0.2lf\n", tt);
    return 0;
}