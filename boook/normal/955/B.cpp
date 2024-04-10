/*input
yeee
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

string s;
map<int , int> cc;
int32_t main(){
	IOS;
	cin >> s;
	REP(i , 0 , s.size()) cc[s[i] - 'a'] ++;
	int sml = INF;
	for(auto to : cc) sml = min(sml , to.S);
	if(s.size() < 4 || cc.size() > 4 || cc.size() == 1) return cout << "No" << endl , 0;
	else if(cc.size() == 2 && sml == 1) return cout << "No" << endl , 0;
	else cout << "Yes" << endl;
    return 0;
}