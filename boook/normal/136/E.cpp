/*input
1??1?
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
vector<string> ans;
int32_t main(){
	IOS;
	cin >> s;
	int cnt = 0 , zero = 0 , one = 0;
	int nn = (int)(s.size());
	int fir = (nn + 1) / 2 , sec = (nn + 0) / 2; 
	// fir remove 1   sec remove 0
	REP(i , 0 , s.size())  cnt += s[i] == '?';
	REP(i , 0 , s.size())  one += s[i] == '1';
	REP(i , 0 , s.size()) zero += s[i] == '0';
	// 0001
	if(fir - 1 >= one) ans.pb("00");
	// 1110
	if(sec - 1 >= zero) ans.pb("11");

	if(one <= fir && zero <= sec){
		int cnt1 = fir -  one;
		int cnt2 = sec - zero;
		int fr , ba;
		vector<int> a , b , c;
		RREP(i , s.size() - 1 , 0){
			if(a.size() <= 1 && s[i] == '0') a.pb(i);
			if(b.size() <= 1 && s[i] == '1') b.pb(i);
			if(c.size() <= 1 && s[i] == '?') c.pb(i);
		}
		// 01
		fr = -1 , ba = -1;
		if(b.size()) ba = max(ba , b[0]);
		if(c.size() && cnt1) ba = max(ba , c[0]);
		if(a.size()) fr = max(fr , a[0]);
		if(cnt2){
			if(c.size() >= 1 && ba != c[0]) fr = max(fr , c[0]);
			if(c.size() >= 2 && ba == c[0]) fr = max(fr , c[1]);
		}
		if(fr >= 0 && ba >= 0 && fr < ba) ans.pb("01");
		// DB4("fr = " , fr , "ba = " , ba);
		//10
		fr = -1 , ba = -1;
		if(a.size()) ba = max(ba , a[0]);
		if(c.size() && cnt2) ba = max(ba , c[0]);
		if(b.size()) fr = max(fr , b[0]);
		if(cnt1){
			if(c.size() >= 1 && ba != c[0]) fr = max(fr , c[0]);
			if(c.size() >= 2 && ba == c[0]) fr = max(fr , c[1]);
		}
		if(fr >= 0 && ba >= 0 && fr < ba) ans.pb("10");
		// DB4("fr = " , fr , "ba = " , ba);
	}
	sort(ALL(ans));
	for(auto to : ans) cout << to << endl;
    return 0;
}