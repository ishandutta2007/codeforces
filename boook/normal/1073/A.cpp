/*input
5
aaaaa
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
const int INF = 0x3f3f3f3f;

string s;
int32_t main(){
	IOS;
	cin >> s >> s;
	REP(i , 1 , s.size()){
		if(s[i - 1] != s[i]){
			cout << "YES" << endl;
			cout << s[i - 1] << s[i] << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}