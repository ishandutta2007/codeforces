/*input
6
RURUUR
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
#define MAX 
#define INF 0x3f3f3f3f

int x = 0 , y = 0;
string s;
int32_t main(){
	IOS;
	cin >> s >> s;
	int pre = 0 , ans = 0;
	REP(i , 0 , s.size()){
		if(s[i] == 'U') y ++;
		if(s[i] == 'R') x ++;
		if(x == y);
		else if(x > y){
			if(pre == -1) ans ++;
			pre = 1;
		}
		else if(y > x){
			if(pre == 1) ans ++;
			pre = -1;
		}
		// DB4(x , y , pre , "");
	}
	cout << ans << endl;
    return 0;
}