/*input
3 5
2 3
1 3
1 2
1 2
1 2
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
#define MAX 300090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int ds[MAX] , siz[MAX];
int Find(int now){ return ds[now] == now ? now : Find(ds[now]); }

int n , m , ans[MAX];
PII x[MAX];
vector<PII> v[MAX * 4];
void update(int now , int l , int r , int ql , int qr , PII val){
	// if(now == 1){
	// 	DB4(ql , qr , val.A , val.B);
	// }
	if(ql <= l && r <= qr) v[now].pb(val);
	else {
		if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
	}
}
int ok = 1;
void solve(int now , int l , int r){
	stack<PII> sol;
	if(ok){
		REP(i , 0 , v[now].size()){
			int v1 = Find(v[now][i].A * 2 + 0);
			int v2 = Find(v[now][i].A * 2 + 1);

			int d1 = Find(v[now][i].B * 2 + 0);
			int d2 = Find(v[now][i].B * 2 + 1);

			if(v1 == d1 || v2 == d2){
				ok = 0;
				sol.push(mp(-1 , -1));
				break;
			}
			else {
				if(v1 == d2 && v2 == d1);
				else {
					// DB4("union = " , v[now][i].A , v[now][i].B , "");
					if(siz[v1] > siz[d2]) swap(v1 , d2);
					siz[d2] += siz[v1];
					ds[v1] = d2;
					sol.push(mp(v1 , d2));
					if(siz[v2] > siz[d1]) swap(v2 , d1);
					siz[d1] += siz[v2];
					ds[v2] = d1;
					sol.push(mp(v2 , d1));
				}
			}
		}
	}

	if(l == r) ans[l] = ok;// , DB4("ans[" , l , "] = " , ok);
	else {
		solve(ls , l , mid + 0);
		solve(rs , mid + 1 , r);
	}
	while(sol.size()){
		PII tmp = sol.top(); sol.pop();
		if(tmp == mp(-1 , -1)) ok = 1;
		else {
			// DB4("break" , tmp.A / 2 , tmp.B / 2 , "");
			ds[tmp.A] = tmp.A;
			siz[tmp.B] -= siz[tmp.A];
		}
	}
}
map<PII , int> cc; 
int32_t main(){
	cin >> n >> m;

	REP(i , 0 , MAX) ds[i] = i , siz[i] = 1;

	REP(i , 1 , m + 1) cin >> x[i].A >> x[i].B;
	REP(i , 1 , m + 1){
		if(cc.find(x[i]) != cc.end()){
			update(1 , 1 , m , cc[x[i]] , i - 1 , x[i]);
			cc.erase(x[i]);
		}
		else cc[x[i]] = i;
	}
	for(auto to : cc) update(1 , 1 , m , to.B , m , to.A);
	solve(1 , 1 , m);
	REP(i , 1 , m + 1){
		if(ans[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}