/*input
4 5
1001
10101
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
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define mod 998244353

string n , m;
int p[MAX] , two[MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> m >> n;
	n = " " + n;
	REP(i , 1 , n.size()) p[i] = p[i - 1] + (n[i] == '1');

	int pos = (int)(n.size()) - 1 , two = 1 , ans = 0;
	RREP(i , (int)m.size() - 1 , 0){
		if(m[i] == '1'){
			// DB4("p[pos] = " , pos , p[pos] , "");
			ans = (ans + two * p[pos]) % mod;
		}
		pos = max(pos - 1 , 0LL);
		two = two * 2 % mod;
	}
	cout << ans << endl;
    return 0;
}