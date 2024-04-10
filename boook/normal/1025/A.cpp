/*input
abc
j
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

string s;

map<char , int>	cc;
int32_t main(){
	IOS;
	cin >> s >> s;
	REP(i , 0 , s.size()) cc[s[i]] ++;
	if(s.size() == 1) return cout << "Yes" << endl , 0;
	int ok = 0;
	for(auto to : cc) if(to.B != 1) ok = 1;
	if(ok == 0) cout << "No" << endl;
	else cout << "Yes" << endl;
    return 0;
}