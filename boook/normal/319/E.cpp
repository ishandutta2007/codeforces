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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid (l + (r - l) / 2)

struct djs{
	int x[MAX] , l[MAX] , r[MAX];
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){
		a = Find(a) , b = Find(b);
		x[a] = b;
		l[b] = min(l[a] , l[b]);
		r[b] = max(r[a] , r[b]);
	}
	int operator[](int now){ return Find(now); }
} ds;
int n , ls[MAX * 70] , rs[MAX * 70] , po = 2;
vector<int> v[MAX * 70];
void update(int now , int l , int r , int ql , int qr , int id){
	if(ql <= l && r <= qr) v[now].pb(id);
	else {
		if(ql <= mid + 0 && ls[now] == 0) ls[now] = po ++;
		if(ql <= mid + 0) update(ls[now] , l , mid + 0 , ql , qr , id);
		if(mid + 1 <= qr && rs[now] == 0) rs[now] = po ++;
		if(mid + 1 <= qr) update(rs[now] , mid + 1 , r , ql , qr , id); 
	}
}
void query(int now , int l , int r , int k , int id){
	for(auto to : v[now]) ds.Union(id , to);
	while(v[now].size() > 1) v[now].pop_back();
	if(now == 0 || l == r) return ;
	if(k <= mid + 0) query(ls[now] , l , mid + 0 , k , id);
	if(mid + 1 <= k) query(rs[now] , mid + 1 , r , k , id);
}
int32_t main(){
    IOS , cin >> n;
    int pos = 1;
    REP(i , 1 , n + 1){
    	int ty , l , r;
    	cin >> ty >> l >> r;
    	if(ty == 1){
    		ds.x[pos] = pos , ds.l[pos] = l , ds.r[pos] = r;
    		query(1 , -INF , INF , l , pos);
    		query(1 , -INF , INF , r , pos);
    		if(l + 1 <= r - 1) update(1 , -INF , INF , l + 1 , r - 1 , pos);
    		pos ++;
    	}
    	if(ty == 2){
    		l = ds[l] , r = ds[r];
    		if(l == r) cout << "YES" << endl;
    		else if(ds.l[r] < ds.l[l] && ds.l[l] < ds.r[r]) cout << "YES" << endl;
    		else if(ds.l[r] < ds.r[l] && ds.r[l] < ds.r[r]) cout << "YES" << endl;
    		else cout << "NO" << endl;
    	}
    }
    return 0;
}