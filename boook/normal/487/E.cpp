/*input
5 6 6
10
40
20
70
30
2 1
1 3
2 3
1 4
1 5
5 4
C 1 50
A 3 1
C 3 60
A 4 1
A 4 3
A 3 4
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , k , x[MAX];
int cut[MAX] , bcc[MAX] , bccpo;
struct Decomposition{
	vector<int> v[MAX];
	multiset<int> dotval[MAX];
	int sml[MAX * 4];
	int pat[MAX] , son[MAX] , siz[MAX] , dep[MAX];
	int top[MAX] , id[MAX] , idpo = 0;
	void DFS1(int now , int fa , int deep){
		pat[now] = fa;
		dep[now] = deep;
		son[now] = 0;
		siz[now] = 1;
		for(auto to : v[now]){
			if(to == fa) continue;
			DFS1(to , now , deep + 1);
			siz[now] += siz[to];
			if(siz[to] > siz[son[now]]) son[now] = to;
		}
	}
	void DFS2(int now , int fa , int root){
		id[now] = ++idpo;
		// DB4("id[" , now , "] = " , idpo);
		top[now] = root;
		if(son[now]) DFS2(son[now] , now , root);
		for(auto to : v[now]){
			if(to == fa || to == son[now]) continue;
			DFS2(to , now , to);
		}
	}
	void update(int now , int l , int r , int k , int v){
		// if(now == 1) DB4("update = " , k , v , "");
		if(l == k && r == k) sml[now] = v;
		else {
			if(k <= mid + 0) update(ls , l , mid + 0 , k , v);
			if(mid + 1 <= k) update(rs , mid + 1 , r , k , v);
			sml[now] = min(sml[ls] , sml[rs]);
		}
	}
	int query(int now , int l , int r , int ql , int qr){
		if(ql > qr) swap(ql , qr);
		if(ql <= l && r <= qr) return sml[now];
		else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
		else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
		return min(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
	}
	int update(int dot , int from , int val){
		dotval[dot].erase(dotval[dot].find(from));
		dotval[dot].insert(val);
		update(1 , 1 , idpo , id[dot] , *dotval[dot].begin());
	}
	int query(int a , int b){
		// cout << "in" << endl;
		int t1 = top[a] , t2 = top[b] , ans = INF;
		while(t1 != t2){
			// DB4(a , t1 , b , t2);
			// if(a == 0 && t1 == 0) break;
			if(dep[t1] < dep[t2]) swap(a , b) , swap(t1 , t2);
			ans = min(ans , query(1 , 1 , idpo , id[a] , id[t1]));
			a = pat[t1] , t1 = top[a];
		}
		int tmp = (id[a] < id[b]) ? a : b;
		if(tmp > n) ans = min(ans , x[pat[tmp]]);
		ans = min(ans , query(1 , 1 , idpo , id[a] , id[b]));
		return ans;
	}
	int print(int now , int l , int r){
		if(l == r) cout << sml[now] << " ";
		else print(ls , l , mid + 0) , print(rs , mid + 1 , r);
	}
	int solveinit(){
		v[0].pb(1);
		DFS1(0 , 0 , 0);
		DFS2(0 , 0 , 0);
		MEM(sml , INF);
		REP(i , 1 , n + 1){
			dotval[i].insert(x[i]);
			dotval[pat[i]].insert(x[i]);
		}
		// REP(i , 1 , bccpo){
		// 	cout << "now i " << i << " = ";
		// 	for(auto to : dotval[i]){
		// 		cout << to << " ";
		// 	} cout << endl;
		// }
		REP(i , 1 , bccpo){
			update(1 , 1 , idpo , id[i] , *dotval[i].begin());
		}
	}
} solver;
struct Tarjan{
	vector<int> v[MAX];
	set<int> cc[MAX];

	int low[MAX] , dep[MAX] , use[MAX];
	stack<PII> sk;
	void DFS(int now , int fa , int deep){
		cut[now] = 0;
		use[now] = 1;
		low[now] = deep;
		dep[now] = deep;
		int son = 0;
		for(auto to : v[now]){
			if(use[to]) low[now] = min(low[now] , dep[to]);
			else {
				sk.push(mp(now , to));
				son ++ , DFS(to , now , deep + 1);
				low[now] = min(low[now] , low[to]);
				if(low[to] >= dep[now]){
					cut[now] = 1;
					while(sk.size()){
						int a = sk.top().A , b = sk.top().B;
						sk.pop();
						cc[bccpo].insert(a);
						bcc[a] = bccpo;
						bcc[b] = bccpo;
						cc[bccpo].insert(b);
						if(now == a && to == b) break;
						if(now == b && to == a) break;
					}
					bccpo ++;
				}
			}
		}
		if(deep == 0) cut[now] = (son >= 2); 
	}
	void Build(){
		REP(i , n + 1 , bccpo){
			for(auto to : cc[i]){
				solver.v[i].pb(to);
				solver.v[to].pb(i);
				// DBGG(i , to);
			}
		}
	}
	void solveinit(){
		MEM(use , 0);
		bccpo = n + 1;
		DFS(1 , 0 , 0);
		Build();
	}
} cuter;
int32_t main(){
	IOS , cin >> n >> m >> k;
	REP(i , 1 , n + 1){
		cin >> x[i];
	}
	REP(i , 1 , m + 1){
		int a , b; cin >> a >> b;
		cuter.v[a].pb(b) , cuter.v[b].pb(a);
	}

	cuter.solveinit();
	solver.solveinit();

	// REP(i , 1 , n + 1) if(cut[i]) DBGG("find one = " , i); 

	char ty;
	int a , b;
	REP(i , 1 , k + 1){
		cin >> ty >> a >> b;
		if(ty == 'A') cout << solver.query(a , b) << endl;
		if(ty == 'C'){
			solver.update(a , x[a] , b);
			solver.update(solver.pat[a] , x[a] , b);
			x[a] = b;
		}
		// cout << "result = "; solver.print(1 , 1 , solver.idpo); cout << endl;
	}
    return 0;
}