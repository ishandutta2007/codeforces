/*input
QAQQQZZYNOIWIN
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
#define MAX 10000
#define INF 0x3f3f3f3f

string s;
int fr[MAX] , ba[MAX];
int32_t main(){
	IOS , cin >> s;
	REP(i , 0 , s.size())      fr[i + 1] = fr[i] + (s[i] == 'Q');
	RREP(i , s.size() - 1 , 0) ba[i + 1] = ba[i + 2] + (s[i] == 'Q');
	int ans = 0;
	REP(i , 0 , s.size()){
		if(s[i] == 'A'){
			ans = ans + fr[i + 1] * ba[i + 1];
		}
	}
	cout << ans << endl;
    return 0;
}