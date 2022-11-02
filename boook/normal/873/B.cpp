/*input
3
111
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , x[MAX];
string s;
map<int , int> cc;
int32_t main(){
	cin >> n >> s;
	REP(i , 0 , s.size()){
		if(s[i] == '0') x[i + 1] = -1;
		if(s[i] == '1') x[i + 1] = 1;
	}
	REP(i , 1 , n + 1) x[i] += x[i - 1];
	cc[0] = 0;
	int ans = 0;
	REP(i , 1 , n + 1){
		if(cc.find(x[i]) == cc.end()){
			cc[x[i]] = i;
		}
		else {
			ans = max(ans , i - cc[x[i]]);
		}
	}
	cout << ans << endl;
    return 0;
}