/*input
4 4
1 4 2
1 2 0
2 3 0
3 4 0
1 4
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
#define MAX 190000
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define N 101000
#define mid ((l + r) >> 1)

int tr[MAX * 130] , ls[MAX * 130] , rs[MAX * 130] , po = 2;

int dis[MAX] , pa[MAX] , two[MAX];
vector<PII> v[MAX];
int n , m , s , t;

int cmp(int r1 , int r2 , int l , int r){
	if(l == r) return tr[r1] < tr[r2];
	if(tr[rs[r1]] == tr[rs[r2]]) return cmp(ls[r1] , ls[r2] , l , mid + 0);
	if(tr[rs[r1]] != tr[rs[r2]]) return cmp(rs[r1] , rs[r2] , mid + 1 , r);
}
struct X{
	int dis , id;
	bool operator < (const X to) const{
		return cmp(to.dis , dis , 0 , N);
	} 
};
PII update(int dot , int l , int r , int k){
	int now = po ++;
	if(po == MAX * 129) {
		cout << "QQ" << endl;
		exit(0);
	}
	tr[now] = tr[dot] , ls[now] = ls[dot] , rs[now] = rs[dot];
	if(l == r){
		tr[now] = 1 - tr[now];
		return mp(now , tr[now]);
	}
	else {
		PII tmp;
		if(mid + 1 <= k){
			tmp = update(rs[now] , mid + 1 , r , k);
			rs[now] = tmp.A;
		}
		else {
			tmp = update(ls[now] , l , mid + 0 , k);
			ls[now] = tmp.A;
			if(tmp.B == 0){
				tmp = update(rs[now] , mid + 1 , r , k);
				rs[now] = tmp.A;
			}
		}
		tr[now] = (tr[ls[now]] + tr[rs[now]] * two[mid - l + 1]) % mod;
		return mp(now , tmp.B);
	}
}
void dijkstra(){
	priority_queue<X> pq;
	pq.push(X{1 , s}) , dis[s] = 1;
	while(pq.size()){
		X now = pq.top(); pq.pop();
		if(now.dis != dis[now.id]) continue;
		if(now.id == t) break;
		for(auto to : v[now.id]){
			int before = po;
			int val = update(now.dis , 0 , N , to.B).A;
			if(dis[to.A] == 0 || cmp(val , dis[to.A] , 0 , N) == 1){
				dis[to.A] = val;
				 pa[to.A] = now.id;
				pq.push(X{dis[to.A] , to.A});
			}
			else po = before;
		}
	} 
	if(dis[t] == 0){
		cout << -1 << endl;
		exit(0);
	}
	else {
		cout << tr[dis[t]] << endl;
		stack<int> sol;
		int now = t;
		while(1){
			sol.push(now);
			if(now == s) break;
			else now = pa[now];
		}
		cout << sol.size() << endl;
		while(sol.size()){
			cout << sol.top() << " ";
			sol.pop();
		}
		cout << endl;
		exit(0);
	}
}
int32_t main(){
	IOS;
	two[0] = 1;
	REP(i , 1 , MAX) two[i] = two[i - 1] * 2 % mod;
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b , c;
		cin >> a >> b >> c;
		v[a].pb(mp(b , c));
		v[b].pb(mp(a , c));
	}
	cin >> s >> t;
	dijkstra();
    return 0;
}