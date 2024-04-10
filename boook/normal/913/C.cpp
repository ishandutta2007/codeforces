/*input
5 787787787
123456789 234567890 345678901 456789012 987654321
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
#define MAX 1000
#define INF 2000000000000000000LL

int n , m , x[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    RREP(i , n - 1 , 1){
        int tmp = x[i] * 2;
        REP(j , i + 1 , n + 1){
            if(tmp < x[j]) x[j] = tmp , tmp *= 2;
            else break;
        }
    }
    int ans = INF , sum = 0;
    // cout << ans << endl;
    RREP(i , n , 1){
        int val = (1 << (i - 1));
        int tmp = m / val;
        m %= val;
        sum += tmp * x[i];
        ans = min(ans , sum + x[i]);
    }
    ans = min(ans , sum);
    cout << ans << endl;
    return 0;
}