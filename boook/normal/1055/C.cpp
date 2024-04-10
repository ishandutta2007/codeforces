/*input
0 1 3
2 3 6
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///----------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int l , r , t;
int a , b , c;
int32_t main(){
	IOS;
	cin >> l >> r >> t;
	cin >> a >> b >> c;
	int val = __gcd(t , c);
	if(val == 1) cout << min(r - l + 1 , b - a + 1) << endl;
	else {
		a += c , b += c;
		int add = (a - l) / val , ans = 0;
		REP(i , add - 100 , add + 100){
			int v1 = l + i * val;
			int v2 = v1 + (r - l);
			ans = max(ans , min(v2 , b) - max(v1 , a) + 1);
		}
		cout << ans << endl;
	}
    return 0;
}