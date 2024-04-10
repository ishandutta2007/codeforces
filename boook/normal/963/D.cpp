/*input
abbb
7
4 b
1 ab
3 bb
1 abb
2 bbb
1 a
2 abbb
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
#define MAX 100090
#define INF 0x3f3f3f3f

int tr[MAX][26] , f[MAX] , last[MAX] , v[MAX] , pos = 0;
int n , ans[MAX] , x[MAX] , len[MAX];
vector<int> sol , sss[MAX];
void insert(string &s , int id , int now = 0){
	REP(i , 0 , s.size()){
		int &to = tr[now][s[i] - 'a'];
		now = to ? to : to = ++pos;
		if(pos + 10 > MAX){
			cout << "QQ" << endl;
			exit(0);
		}
	}
	if(v[now]) ans[id] = v[now];
	else v[now] = id;
}
void getac(){
	queue<int> qu;
	REP(i , 0 , 26) if(tr[0][i]) qu.push(tr[0][i]);
	while(qu.size()){
		int now = qu.front(); qu.pop();
		sol.pb(now);
		REP(i , 0 , 26){
			int to = tr[now][i] , tmp;
			if(to == 0) tr[now][i] = tr[f[now]][i];
			else {
				qu.push(to) , tmp = f[now];
				while(tmp && tr[tmp][i] == 0) tmp = f[tmp];
				f[to] = tr[tmp][i];
				last[to] = v[f[to]] ? f[to] : last[f[to]];
			}
		}
	}
}
void Print(int now , int id){
	int to = v[now];
	sss[to].pb(id);
	if(sss[to].size() >= x[to]){
		int tmp = sss[to][sss[to].size() - 1] - sss[to][sss[to].size() - x[to]];
		ans[to] = min(ans[to] , tmp);
	}
	if(last[now]) Print(last[now] , id);
}
void solve(string &s , int now = 0){
	REP(i , 0 , s.size()){
		now = tr[now][s[i] - 'a'];
		if(v[now]) Print(now , i);
		else if(last[now]) Print(last[now] , i);
	}
}
string p , s;
int32_t main(){
    IOS;
    cin >> p >> n;
    REP(i , 1 , n + 1) cin >> x[i] >> s , len[i] = s.size() , insert(s , i);
    REP(i , 1 , n + 1) ans[i] = INF;
    getac();
    solve(p);
    REP(i , 1 , n + 1){
    	if(ans[i] == INF) cout << -1 << endl;
    	else cout << ans[i] + len[i] << endl;
    }
    return 0;
}