/*input
abacaba
2
3 6 1
1 4 2
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

string s;
int n;
int32_t main(){
	cin >> s;
	cin >> n;
	REP(i , 1 , n + 1){
		int l , r , k;
		cin >> l >> r >> k;
		int len = (r - l + 1);
		k %= len;
		if(k){
			int id = r - k + 1;
			string tmp = s.substr(id - 1 , k);
			// DB4("id = " , id , "tmp = " , tmp);
			// DBGG("here = " , s);
			s.erase(id - 1 , k);
			// DBGG("here = " , s);
			s.insert(l - 1 , tmp);
		}
	}
		cout << s << endl;
    return 0;
}