/*input
2
?ab
??b
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n;
string s[MAX];
int32_t main(){
	cin >> n;
	REP(i , 0 , n) cin >> s[i];
	string ans;
	REP(j , 0 , s[0].size()){
		int now = -1;
		REP(i , 0 , n){
			if(s[i][j] == '?') continue;
			else {
				if(now == -1 || now == s[i][j] - 'a') now = s[i][j] - 'a';
				else now = -2;
			}
		}
		if(now == -1) now = 0;
		if(now == -2) ans += "?";
		else ans += "a" , ans[ans.size() - 1] += now;
	}
	cout << ans << endl;
    return 0;
}