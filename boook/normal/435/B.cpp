/*input
9090000078001234 6
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
int k;
int32_t main(){
	IOS;
	cin >> s >> k;
	REP(i , 0 , s.size()){
		PII tmp = mp(s[i] - '0' , 0);
		REP(j , i + 1 , s.size()){
			if(j - i <= k) tmp = max(tmp , mp(s[j] - '0' , -(j - i)));
		}
		int res = -tmp.B;
		k -= res;
		// cout << tmp.A << endl;
		RREP(j , i + res , i + 1) s[j] = s[j - 1];
		s[i] = tmp.A + '0';
	}
	cout << s << endl;
    return 0;
}