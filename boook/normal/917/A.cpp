/*input
??()??
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
#define MAX 
#define INF 0x3f3f3f3f

string s;
int32_t main(){
	IOS;
	cin >> s;
	int ans = 0;
	REP(i , 0 , s.size()){
		int l = 0 , r = 0 , can = 0 , ok = 1;
		REP(j , i , s.size()){
			if(s[j] == '(') l ++ , ok = 0;
			if(s[j] == ')') r ++ , ok = 1;
			if(s[j] == '?') r ++ , can ++ , ok = 1;
			if(l < r){
				if(can) r -- , l ++ , can --;
				else break;
			}
			if(ok && i % 2 != j % 2 && l == r){
				ans ++;
				// DBGG(i , j);
			// cout << ok << " " , DB4(i , j , cnt , good);
			}
		}
	}
	cout << ans << endl;
    return 0;
}