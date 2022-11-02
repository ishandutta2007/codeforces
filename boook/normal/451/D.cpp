/*input
babaa
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
int ans[2];
int cnt[2];
void solve(){
	MEM(cnt , 0);
	REP(i , 0 , s.size()){
		if(i % 2 == 0 && s[i] == 'a') cnt[0] ++;
		if(i % 2 == 1 && s[i] == 'a') cnt[1] ++;
		if(i % 2 == 0 && s[i] == 'a'){
			ans[0] += cnt[1];
			ans[1] += cnt[0];
		}
		if(i % 2 == 1 && s[i] == 'a'){
			ans[0] += cnt[0];
			ans[1] += cnt[1];
		}
	}
}
int32_t main(){
	IOS , cin >> s;
	solve();
	REP(i , 0 , s.size()){
		if(s[i] == 'a') s[i] = 'b';
		else if(s[i] == 'b') s[i] = 'a';
	}
	solve();
	cout << ans[0] << " " << ans[1] << endl;
    return 0;
}