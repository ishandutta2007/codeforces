/*input
10
2 5 3 2 3 5 3 4 2 4
10
C 10 6
A 2 6
A 1 3
C 3 4
A 3 11
A 4 9
A 5 6
C 7 3
A 8 10
A 2 5
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , x[MAX];
struct N{
	int x[65];
}b[MAX * 4];
N Pull(N l , N r){
	N ans;
	REP(i , 0 , 60){
		ans.x[i] = l.x[i] + r.x[(i + l.x[i]) % 60];
	}
	return ans;
}
void update(int now , int l , int r , int id){
	if(l == id && r == id){
		REP(i , 0 , 60){
			if(i % x[id] == 0) b[now].x[i] = 2;
			if(i % x[id] != 0) b[now].x[i] = 1;
		}	
	}
	else{
		if(id <= mid + 0) update(ls , l , mid + 0 , id);
		if(mid + 1 <= id) update(rs , mid + 1 , r , id);
		b[now] = Pull(b[ls] , b[rs]);
	}
}
N query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return b[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return Pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	cin >> m;
	REP(i , 1 , n + 1) update(1 , 1 , n , i);
	REP(i , 1 , m + 1){
		int a , b;
		string ty;
		cin >> ty >> a >> b;
		if(ty == "C") x[a] = b , update(1 , 1 , n , a);
		else cout << query(1 , 1 , n , a , b - 1).x[0] << endl;
	}
    return 0;
}