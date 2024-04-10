/*input
7 2 3
1111111
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
#define MAX 300900
#define INF 1e17

int n , a , b;
string s;
int32_t main(){
	IOS;
	cin >> s >> a >> b >> s;
	int zero = s[0] == '0' , ans = INF;
	REP(i , 1 , s.size()){
		if(s[i - 1] == '1' && s[i] == '0') zero ++;
	}
	if(zero == 0) return cout << 0 << endl , 0;
	REP(i , 0 , zero){
		// cout << i * a + (zero - i) * b << endl;
		ans = min(ans , i * a + (zero - i) * b);
	}
	cout << ans << endl;
    return 0;
}