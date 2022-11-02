/*input
3
kek
preceq
cheburek
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , p[30][30] , u[30][30] , nxt[30] , pre[30] , use[30];
string s;

int32_t main(){
	cin >> n;
	set<char> cc;
	REP(i , 1 , n + 1){
		cin >> s;
		REP(j , 1 , s.size()){
			p[s[j - 1] - 'a'][s[j] - 'a'] = 1;
			u[s[j] - 'a'][s[j - 1] - 'a'] = 1;
		}
		REP(j , 0 , s.size()) cc.insert(s[j]);
	}
	REP(i , 0 , 26){
		if(p[i][i] == 1) return cout << "NO" << endl , 0;
		int cnt = 0 , res = 0;
		REP(j , 0 , 26){
			if(p[i][j] == 1) cnt ++;
			if(u[i][j] == 1) res ++;
		}
		if(cnt > 1) return cout << "NO" << endl , 0;
		if(res > 1) return cout << "NO" << endl , 0;
	}
	MEM(pre , -1) , MEM(nxt , -1);
	REP(i , 0 , 26){
		REP(j , 0 , 26){
			if(p[i][j] == 1) nxt[i] = j , pre[j] = i;

		}
	}
	string ans;
	while(1){
		int now = -1;
		RREP(i , 25 , 0) if(use[i] == 0 && pre[i] == -1 && cc.find(i + 'a') != cc.end()) now = i;
		if(now == -1) break;
		while(use[now] == 0){
			use[now] = 1;
			ans += 'a' + now;
			if(nxt[now] == -1) break;
			now = nxt[now];
		}
	}
	if(ans.size() != cc.size()) cout << "NO" << endl;
	else cout << ans << endl;
    return 0;
}