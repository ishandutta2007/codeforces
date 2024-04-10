/*input
3
ABC DEF
ABC EFG
ABD OOO
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
#define MAX 5010
#define INF 0x3f3f3f3f

int use[MAX] , scc[MAX] , sccpo;
vector<int> G1[MAX] , G2[MAX] , p;
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
void ADDE(int a , int b){
	// DB4("a = " , a , "b = " , b);
	G1[a].pb(b);
	G2[b].pb(a);
}
int n , sol[MAX];
string s[MAX][2];
int cmp(int a , int b){ return s[a][0] < s[b][0]; }
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> s[i][0] >> s[i][1];
	REP(i , 1 , n + 1) s[i][0] = s[i][0].substr(0 , 3);
	REP(i , 1 , n + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + n , cmp);

	REP(i , 2 , n + 1){
		int fr = sol[i - 1] , ba = sol[i];
		if(s[fr][0] == s[ba][0]){
			ADDE(fr , fr + n);
			ADDE(ba , ba + n);
		}
	}
	REP(i , 1 , n + 1){
		REP(j , 1 , n + 1){
			if(i == j) continue;
			string ii = s[i][0].substr(0 , 2) + s[i][1][0];
			string jj = s[j][0].substr(0 , 2) + s[j][1][0];
			if(s[i][0] == s[j][0]) ADDE(i , j + n);
			if(s[i][0] == jj) ADDE(i , j);
			if(ii == jj) ADDE(i + n , j);
			if(ii == s[j][0]) ADDE(i + n , j + n);
		}
	}
	REP(i , 1 , n + n + 1) DFS1(i);
	RREP(i , p.size() - 1 , 0){
		if(scc[p[i]] == 0){
			sccpo ++;
			DFS2(p[i]);
		}
	}
	REP(i , 1 , n + 1){
		if(scc[i] == scc[i + n]) return cout << "NO" << endl , 0;
	}
	cout << "YES" << endl;
	REP(i , 1 , n + 1){
		if(scc[i] > scc[i + n]) cout << s[i][0] << endl;
		else cout << s[i][0].substr(0 , 2) << s[i][1][0] << endl;
	}
    return 0;
}