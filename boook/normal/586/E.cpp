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
#define MAX 
#define INF 0x3f3f3f3f

int n , m;

int32_t main(){
    cin >> n >> m;
    if(__gcd(n , m) != 1) return 0 * puts("Impossible");
    while(n && m){
        if(n > m){
            int tmp = n / m;
            cout << ((n % m == 0) ? tmp - 1 : tmp) << "A" ;
            if(n % m == 0) assert(m == 1);
            n -= tmp * m;
        }else {
            int tmp = m / n;
            cout << ((m % n == 0) ? tmp - 1 : tmp) << "B" ;
            if(m % n == 0) assert(n == 1);
            m -= tmp * n;
        }
    }
    cout << endl;
    return 0;
}