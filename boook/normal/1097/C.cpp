/*input
2
(())
()
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

map<int , int> cc;
int ans = 0 , n;
string s;

int32_t main(){
	IOS;
	cin >> n;
	REP(ii , 1 , n + 1){
		cin >> s;
		int r = 0 , l = 0;
		REP(j , 0 , s.size()){
			if(s[j] == '('){
				l ++;
			}
			if(s[j] == ')'){
				if(l != 0) l --;
				else r ++;
			}
		}
		// DB4(s , " = " , r , l);
		if(r != 0 && l != 0);
		else{
			int tmp = l - r;
			if(cc[-tmp] > 0) ans ++ , cc[-tmp] --;
			else cc[tmp] ++;
		}
	}
	cout << ans << endl;
    return 0;
}