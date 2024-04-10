/*input
2
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define PII pair<int , int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define DBGG(i , j) cout << i << " " << j << endl
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)
#define int long long
int n , ans = 0;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 2 , n + 1){
    	for(int j = i + i ; j <= n ; j += i){
    		ans += j / i * 4;
    	}
    }
    cout << ans << endl;
    return 0;
}