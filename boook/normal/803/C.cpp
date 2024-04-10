/*input
5 3
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
#define MAX 
#define INF 0x3f3f3f3f

int n , k;
int gcd = -1;
int F(int now){
    int tmp = floor(sqrt(now * 2 - k));
    return tmp >= k;
     // >= k * k + k
}
int32_t main(){
    cin >> n >> k;
    REP(i , 1 , n + 1){
        if(i * i > n) break;
        if(n % i == 0){
            if(F(i)) gcd = max(gcd , n / i);
            if(F(n / i)) gcd = max(gcd , i);
        }
    }
    if(gcd == -1) cout << -1 << endl;
    else {
        int res = n / gcd;
        REP(i , 1 , k + 1){
            if(i == k) cout << res * gcd << endl;
            else cout << i * gcd << " " , res -= i;
        }
    }
    return 0;
}