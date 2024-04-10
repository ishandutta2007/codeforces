/*input
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8
1 2
1 3
1 4
2 3
5 3
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
#define MAX 100090
#define INF 0x3f3f3f3f

struct N{
	int pri , siz;
	PII val;
	N *l , *r;
	N(PII V){
		l = r = NULL;
		val = V;
		pri = (rand() << 16 | rand());
		siz = 1;
	}
};
int SIZ(N *now){ return now ? now->siz : 0; }
void Pull(N *now){ now->siz = SIZ(now->l) + SIZ(now->r) + 1; }
N* Merge(N *a , N *b){
	if(!a || !b) return a ? a : b;
	if(a->pri > b->pri){
		a->r = Merge(a->r , b);
		return Pull(a) , a;
	}
	else {
		b->l = Merge(a , b->l);
		return Pull(b) , b;
	}
}
void Split(N *t , PII k , N *&a , N *&b){
	if(!t) return a = b = NULL , void();
	if(k <= t->val)
		b = t , Split(t->l , k , a , b->l);
	else
		a = t , Split(t->r , k , a->r , b);
	Pull(t);
}
void put(N *now){
	if(now->l) put(now->l);
	cout << now->val.A << "-" << now->val.B << " ";
	if(now->r) put(now->r);
}
N *root[MAX];
int n , m , dep[MAX] , sol[MAX] , ans[MAX] , solpo = 1;
map<int , int> cc[MAX];
vector<int> v[MAX] , g[MAX] , id[MAX];

void DFS(int now , int fa , int deep){
	dep[now] = deep;
	for(auto to : v[now]){
		if(to == fa) continue;
		DFS(to , now , deep + 1);
	}
	sol[solpo ++] = now;
}
N* Insert(N *now , PII val){
	N *left , *right;
	Split(now , val , left , right);
	return Merge(left , Merge(new N(val) , right));
}
N *Remove(N *now , PII val){
	N *left , *mid , *right , *tmp;
	Split(now , mp(val.A , val.B + 0) , left , tmp);
	Split(tmp , mp(val.A , val.B + 1) , mid , right);
	return Merge(left , right);
}
void update(int a , int b){
	int swp = 0;
	if(cc[a].size() < cc[b].size()) swap(a , b) , swp = 1;
	for(auto to : cc[b]){
		int now = to.A , cnt = to.B , add = 0;
		if(cc[a].find(to.A) != cc[a].end()){
			add = cc[a][to.A];
			cc[a][to.A] = cnt + add;
			root[a] = Remove(root[a] , mp(add +   0 , to.A));
			root[a] = Insert(root[a] , mp(cnt + add , to.A));
		}
		else {
			root[a] = Insert(root[a] , mp(cnt +   0 , to.A));
			cc[a][to.A] = cnt;
		}
	}
	if(swp) swap(root[a] , root[b]) , swap(cc[a] , cc[b]);
}
int query(int now , int num){
	N *left , *right;
	Split(root[now] , mp(num , 0) , left , right);
	int tmp = SIZ(right);
	root[now] = Merge(left , right);
	return tmp;
}
void solve(){
	REP(ii , 1 , n + 1){
		int now = sol[ii];
		for(auto to : v[now]){
			if(dep[to] < dep[now]) continue;
			update(now , to);
		}
		// cout << "solveing now now = " << now << endl;
		// put(root[now]) , cout << endl;
		REP(j , 0 , g[now].size()){
			ans[id[now][j]] = query(now , g[now][j]);
		}
	}
}
inline int rit(){
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		res = (res << 1) + (res << 3) + c - '0';
		c = getchar();
	}return res;
}
int32_t main(){
	srand(time(NULL));
	n = rit() , m = rit();
	REP(i , 1 , n + 1){
		int in = rit();
		root[i] = Merge(root[i] , new N(mp(1 , in)));
		cc[i][in] = 1;
	}
	REP(i , 2 , n + 1){
		int a = rit() , b = rit();
		v[a].pb(b);
		v[b].pb(a);
	}
	REP(i , 1 , m + 1){
		int a = rit() , b = rit();
		 g[a].pb(b);
		id[a].pb(i);
	}

	DFS(1 , 0 , 0);
	solve();
	REP(i , 1 , m + 1) printf("%d\n", ans[i]);
    return 0;
}