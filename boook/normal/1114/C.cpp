/*input
38 11
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , m , ans;
void solve(int val , int cnt){
    int res = 0 , nn = n;
    while(nn) res += nn / val , nn /= val;
    ans = min(ans , res / cnt);
}
int32_t main(){
    IOS;
    cin >> n >> m , ans = n;
    REP(i , 2 , m + 1){
        if(i * i > m) break;
        if(m % i == 0){
            int cnt = 0;
            while(m % i == 0) m /= i , cnt ++;
            solve(i , cnt);
        }
    }
    if(m != 1) solve(m , 1);
    cout << ans << endl;
    return 0;
}