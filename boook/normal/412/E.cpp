/*input
.asd123__..@
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
#define INF 0x3f3f3f3f

string s;
int32_t main(){
	cin >> s;
	int ans = 0;
	REP(i , 0 , s.size()){
		if(s[i] != '@') continue;
		int fr = 0 , ba = 0 , ok = 0;
		RREP(j , i - 1 , 0){
			if(isalpha(s[j]) == 0 && isdigit(s[j]) == 0 && s[j] != '_') break;
			if(isalpha(s[j])) fr ++;
		}
		REP(j , i + 1 , s.size()){
			if(ok == 0){
				if(s[j] == '.' && j == i + 1) break;
				else if(s[j] == '.') ok = 1;
				else if(isalpha(s[j]) == 0 && isdigit(s[j]) == 0) break;
			} 
			else {
				if(isalpha(s[j])) ba ++;
				else break;
			}
		}
		ans += fr * ba;
	}
	cout << ans << endl;
    return 0;
}