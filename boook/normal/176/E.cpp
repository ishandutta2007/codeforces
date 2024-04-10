/*input
6
1 2 1
1 3 5
4 1 7
4 5 3
6 4 2
10
+ 3
+ 1
?
+ 6
?
+ 5
?
- 6
- 3
?
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
#define MAX 100090
#define INF 0x3f3f3f3f
#define LOG 18

int n , m;
int in[MAX] , ot[MAX] , dep[MAX] , sp[MAX][LOG + 1] , pos = 0;
vector<PII> v[MAX];
int FA(int a , int b){
	return in[a] <= in[b] && ot[b] <= ot[a];
}
int LCA(int a , int b){
	if(FA(a , b)) return a;
	RREP(i , LOG , 0) if(FA(sp[a][i] , b) == 0) a = sp[a][i];
	return sp[a][0];
}
int DIS(int a , int b){
	return dep[a] + dep[b] - dep[LCA(a , b)] * 2;
}
void DFS(int now , int fa , int deep){
	dep[now] = deep;
	sp[now][0] = fa;
	in[now] = ++ pos;
	for(auto to : v[now]) if(to.A != fa) DFS(to.A , now , deep + to.B);
	ot[now] = ++ pos;
}
void solveinit(){
	DFS(1 , 1 , 0) , ot[0] = pos ++;
	REP(i , 1 , LOG + 1) REP(j , 1 , n + 1) 
		sp[j][i] = sp[sp[j][i - 1]][i - 1];
}

int32_t main(){
	IOS;
	cin >> n;
	REP(i , 2 , n + 1){
		int a , b , c;
		cin >> a >> b >> c;
		v[a].pb(mp(b , c));
		v[b].pb(mp(a , c));
	}
	solveinit();
	cin >> m;

	set<PII> cc;
	int ans = 0;
	REP(i , 1 , m + 1){
		string s; int val;
		cin >> s;
		if(s == "?") cout << ans / 2 << endl;
		if(s == "+"){
			cin >> val;
			cc.insert(mp(in[val] , val));
			if(cc.size() >= 2){
				auto tmp = cc.find(mp(in[val] , val));
				PII fr = (tmp != cc.begin())     ? *prev(tmp) : *prev(cc.end());
				PII ba = (next(tmp) != cc.end()) ? *next(tmp) : *cc.begin();
				ans -= DIS(fr.B , ba.B);
				ans += DIS(fr.B ,  val);
				ans += DIS( val , ba.B);
			}
		}
		if(s == "-"){
			cin >> val;
			if(cc.size() >= 2){
				auto tmp = cc.find(mp(in[val] , val));
				PII fr = (tmp != cc.begin())     ? *prev(tmp) : *prev(cc.end());
				PII ba = (next(tmp) != cc.end()) ? *next(tmp) : *cc.begin();
				ans += DIS(fr.B , ba.B);
				ans -= DIS(fr.B ,  val);
				ans -= DIS( val , ba.B);
			}
			cc.erase(mp(in[val] , val));
		}
	}
    return 0;
}