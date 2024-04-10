/*input
3 2
cat
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
string s;
int32_t main(){
	IOS;
	cin >> n >> m;
	cin >> s;
	int ok = 0;
	string tmp;
	REP(i , 1 , s.size()){
		int len = s.size() - i;
		if(s.substr(i , len) == s.substr(0 , len)){
			tmp = s.substr(len , s.size());
			ok = len;
			break;
		}
	}
	// DBGG("ok = " , ok);
	if(ok == 0){
		REP(i , 0 , m) cout << s ; cout << endl;
	}
	else {
		cout << s;
		REP(i , 0 , m - 1) cout << tmp;
		cout << endl;
	}
    return 0;
}