/*input
2
aaaaaaaaaaaaaa
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int ans = 0;
string s;
int32_t main(){
	IOS;
	cin >> s >> s;
	string p = s;
	sort(ALL(p));
	if(p[0] == p.back()){
		int a = p.size();
		cout << a * (a + 1) / 2 << endl;
	}
	else if(s[0] != s.back()){
		int pos = 0 , c1 = 1;
		while(pos + 1 < s.size() && s[pos + 1] == s[0]) pos ++ , c1 ++;
		int suf = s.size() - 1 , c2 = 1;
		while(suf - 1 >= 0 && s[suf - 1] == s.back()) suf -- , c2 ++;
		int ans = 1 + c1 + c2;
		// DB4(1 , c1 , c2 , "");
		cout << ans % 998244353  << endl;
	}
	else {
		int pos = 0 , c1 = 2;
		while(pos + 1 < s.size() && s[pos + 1] == s[0]) pos ++ , c1 ++;
		int suf = s.size() - 1 , c2 = 2;
		while(suf - 1 >= 0 && s[suf - 1] == s.back()) suf -- , c2 ++;
		int ans = c1 * c2;
		cout << ans % 998244353  << endl;

	}
    return 0;
}