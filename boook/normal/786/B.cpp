/*input
4 3 1
3 4 1 3 12
2 2 3 4 10
1 2 4 16
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
#define INF 10000000000000000LL
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , s , idu[MAX * 4] , idd[MAX * 4] , id[MAX] , po = 0;
int dis[MAX * 10];
vector<PII> v[MAX * 10];
void Build(int now , int l , int r){
	if(l == r){
		v[idu[now]].pb(mp(id[l] , 0));
		v[id[l]].pb(mp(idu[now] , 0));
		v[idd[now]].pb(mp(id[l] , 0));
		v[id[l]].pb(mp(idd[now] , 0));
	}
	else {
		v[idd[now]].pb(mp(idd[ls] , 0));
		v[idd[now]].pb(mp(idd[rs] , 0));
		v[idu[ls]].pb(mp(idu[now] , 0));
		v[idu[rs]].pb(mp(idu[now] , 0));
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
	}
}
int update1(int now , int l , int r , int ql , int qr , int from , int val){
	if(ql <= l && r <= qr) v[from].pb(mp(idd[now] , val));
	else {
		if(ql <= mid + 0) update1(ls , l , mid + 0 , ql , qr , from , val);
		if(mid + 1 <= qr) update1(rs , mid + 1 , r , ql , qr , from , val);
	}
}
int update2(int now , int l , int r , int ql , int qr , int to , int val){
	if(ql <= l && r <= qr) v[idu[now]].pb(mp(to , val));
	else {
		if(ql <= mid + 0) update2(ls , l , mid + 0 , ql , qr , to , val);
		if(mid + 1 <= qr) update2(rs , mid + 1 , r , ql , qr , to , val);
	}	
}
int32_t main(){
	IOS , cin >> n >> m >> s;
	REP(i , 0 , MAX * 4) idu[i] = po ++;
	REP(i , 0 , MAX * 4) idd[i] = po ++;
	REP(i , 0 , MAX * 1)  id[i] = po ++;
	Build(1 , 1 , n);

	REP(i , 1 , m + 1){
		int ty , now , l , r , val;
		cin >> ty;
		if(ty == 1){
			cin >> now >> r >> val;
			v[id[now]].pb(mp(id[r] , val));
		}
		if(ty == 2){
			cin >> now >> l >> r >> val;
			update1(1 , 1 , n , l , r , id[now] , val);
		}
		if(ty == 3){
			cin >> now >> l >> r >> val;
			update2(1 , 1 , n , l , r , id[now] , val);
		}
	}
	REP(i , 0 , MAX * 10) dis[i] = INF;
	priority_queue<PII , vector<PII> , greater<PII> > pq;
	pq.push(mp(0 , id[s])) , dis[id[s]] = 0;
	while(pq.size()){
		int now = pq.top().B;
		int step = pq.top().A;
		// DB4("now = " , now , "step = " , step);
		pq.pop();
		if(dis[now] != step) continue;
		for(auto to : v[now]){
			if(dis[to.A] > dis[now] + to.B){
				dis[to.A] = dis[now] + to.B;
				pq.push(mp(dis[to.A] , to.A));
			}
		}
	}
	REP(i , 1 , n + 1) cout << (dis[id[i]] == INF ? -1 : dis[id[i]]) << " ";
	cout << endl;
    return 0;
}