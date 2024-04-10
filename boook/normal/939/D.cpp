/*input
8
drpepper
cocacola
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
#define MAX 60
#define INF 0x3f3f3f3f

int n;
string s1 , s2;
// struct djs{
// 	int x[MAX];
// 	void init(){ REP(i , 0 , MAX) x[i] = i; }
// 	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
// 	void Union(int a , int b){ x[Find(a)] = Find(b); }
// 	int operator[](int now){ return Find(now); }
// } ds;
vector<int> v[30] , p;
vector<PII> ans;
int use[MAX];
void DFS(int now){
	if(use[now]) return ;
	use[now] = 1;
	for(auto to : v[now]) DFS(to);
	p.pb(now);
}
int32_t main(){
	IOS;
	cin >> n >> s1 >> s2;
	// ds.init();
	REP(i , 0 , n){
		if(s1[i] != s2[i]){
			v[s1[i] - 'a'].pb(s2[i] - 'a');
			v[s2[i] - 'a'].pb(s1[i] - 'a');
		}
		// if(s1[i] != s2[i]) ds.Union(s1[i] - 'a' , s2[i] - 'a');
	}
	REP(i , 0 , 26){
		p.clear();
		DFS(i);
		if(p.size() <= 1) continue;
		REP(j , 1 , p.size()){
			ans.pb(mp(p[j - 1] , p[j]));
		}
	}
	cout << ans.size() << endl;
	for(auto to : ans) cout << (char)('a' + to.A) << " " << (char)('a' + to.B) << endl;
    return 0;
}