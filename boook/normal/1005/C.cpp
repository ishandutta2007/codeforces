/*input
4
1 1 1 1023
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200000
#define INF 0x3f3f3f3f

int n , x[MAX];
map<int , int> cc;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) cc[x[i]] ++;
    int ans = 0;
    REP(i , 1 , n + 1){
    	int ok = 0;
    	REP(j , 0 , 40){
    		int val = (1LL << j);
    		if(val > x[i] && cc.count(val - x[i]) && val != x[i] + x[i]) ok = 1;
    		if(val == x[i] + x[i] && cc[x[i]] >= 2) ok = 1;
    		if(ok) break;
    	}
    	ans += ok;
    }
    cout << n - ans << endl;
    return 0;
}