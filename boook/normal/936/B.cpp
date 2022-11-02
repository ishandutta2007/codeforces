/*input
6 6
1 2
2 3 4
1 5
1 5
1 6
0
1
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , s , can[MAX][2];
vector<int> v[MAX] , G1[MAX] , G2[MAX] , p;

int use[MAX] , scc[MAX] , sccpo;
void DFS1(int now){
	if(use[now]) return ;
	use[now] = 1;
	for(auto to : G1[now]) DFS1(to);
	p.pb(now);
}
void DFS2(int now){
	if(scc[now]) return ;
	scc[now] = sccpo;
	for(auto to : G2[now]) DFS2(to);
}
void solveinit(){
	DFS1(s);
	RREP(i , p.size() - 1 , 0){
		if(scc[p[i]] == 0){
			sccpo ++;
			DFS2(p[i]);
		}
	}
}
int T[MAX];
void DFS(int now){
	if(T[scc[now]] == 0) T[scc[now]] = now;
	else if(T[scc[now]] != now){
		cout << "Draw" << endl;
		exit(0);
	}
	for(auto to : v[now]) DFS(to);
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1){
		int in , to;
		cin >> in;
		REP(j , 1 , in + 1){
			cin >> to;
			v[i].pb(to);
			G1[i].pb(to);
			G2[to].pb(i);
		}
	}
	cin >> s;
	queue<int> qu;
	can[s][0] = -1 , qu.push(s * 2 + 0);
	while(qu.size()){
		int now  = qu.front() / 2;
		int type = qu.front() % 2;
		qu.pop();
		for(auto to : v[now]){
			if(can[to][1 - type] == 0){
				can[to][1 - type] = now;
				qu.push(to * 2 + (1 - type));
			}
		}
	}
	REP(i , 1 , n + 1) if(v[i].size() == 0 && can[i][1] != 0){
		cout << "Win" << endl;
		int now = i , type = 1;
		vector<int> ans;
		while(1){
			ans.pb(now);
			if(can[now][type] == -1) break; 
			now = can[now][type];
			type = 1 - type;
		}
		reverse(ALL(ans));
		for(auto to : ans) cout << to << " "; cout << endl;
		return 0;
	}
	solveinit();
	// REP(i , 1 , n + 1) DBGG(i , scc[i]);
	DFS(s);
	cout << "Lose" << endl;
    return 0;
}