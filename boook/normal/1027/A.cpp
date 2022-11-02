/*input
5
6
abccba
2
cf
4
adfa
8
abaazaba
2
ml
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

int t , n;
string s;
int solve(char a , char b){
	if(a == b) return 1;
	vector<int> fr , ba;
	if(a == 'a') fr.pb('b');
	else if(a == 'z') fr.pb('y');
	else fr.pb(a + 1) , fr.pb(a - 1);

	if(b == 'a') ba.pb('b');
	else if(b == 'z') ba.pb('y');
	else ba.pb(b + 1) , ba.pb(b - 1);
	for(auto to : fr) for(auto ot : ba) if(to == ot){
		// cout << to << " " << ot << endl;
		return 1;
	}
	return 0;
}
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 0 , t){
		cin >> n;
		cin >> s;
		int ok = 1;
		REP(i , 0 , s.size()) if(solve(s[i] , s[s.size() - 1 - i]) == 0) ok = 0;
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}