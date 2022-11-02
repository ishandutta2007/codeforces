/*input
3
1 2 3
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
#define MAX 300090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

struct N{
	int tag;
	PII sml , sec;
} st[MAX * 4];

N pull(N a , N b){
	N ans;
	ans.tag = 0;
	ans.sml = a.sml;
	ans.sec = a.sec;

	     if(b.sml.A == ans.sml.A) ans.sml.B += b.sml.B;
	else if(b.sml.A == ans.sec.A) ans.sec.B += b.sml.B;
	else {
		if(  b.sml < ans.sec) swap(  b.sml , ans.sec);
		if(ans.sec < ans.sml) swap(ans.sec , ans.sml);
	}
		 if(b.sec.A == ans.sml.A) ans.sml.B += b.sec.B;
	else if(b.sec.A == ans.sec.A) ans.sec.B += b.sec.B;
	else {
		if(  b.sec < ans.sec) swap(  b.sec , ans.sec);
		if(ans.sec < ans.sml) swap(ans.sec , ans.sml);
	}

	return ans;
}
void push(int now , int l , int r){
	if(l != r){
		st[ls].tag += st[now].tag;
		st[ls].sml.A += st[now].tag;
		st[ls].sec.A += st[now].tag;

		st[rs].tag += st[now].tag;
		st[rs].sml.A += st[now].tag;
		st[rs].sec.A += st[now].tag;
		st[now].tag = 0;
	}
}
void build(int now , int l , int r){
	if(l == r){
		st[now].tag = 0;
		st[now].sml = mp(100 , 1);
		st[now].sec = mp(INF , 0);
	}
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		st[now] = pull(st[ls] , st[rs]);
	}
}
void update(int now , int l , int r , int ql , int qr , int val){
	assert(ql <= qr);
	push(now , l , r);
	if(ql <= l && r <= qr){
		st[now].tag += val;
		st[now].sml.A += val;
		st[now].sec.A += val;
	}
	else {
		if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
		st[now] = pull(st[ls] , st[rs]);
	}
}
void print(int now , int l , int r){
	push(now , l , r);
	if(l == r) cout << st[now].sml.A << " ";
	else {
		print(ls , l , mid + 0);
		print(rs , mid + 1 , r);
	}
	if(now == 1) cout << endl;
}
int n , x[MAX] , att[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) att[x[i]] = i;

	x[0] = x[n + 1] = INF;
	int ans = 0;
	build(1 , 1 , n);
		// DB4(st[1].sml.A , st[1].sml.B , st[1].sec.A , st[1].sec.B);
		// return 0;
	REP(i , 1 , n + 1){
		update(1 , 1 , n , i , i , -100);
		int fr = x[att[i] - 1] , ba = x[att[i] + 1];
		// DB4("fr = " , fr , "ba = " , ba);
		if(fr < i && ba < i){
			update(1 , 1 , n , 1 , min(fr , ba) , -1);
			update(1 , 1 , n , max(fr , ba) + 1 , i , 1);
		}
		else if(fr < i) update(1 , 1 , n , fr + 1 , i , 1);
		else if(ba < i) update(1 , 1 , n , ba + 1 , i , 1);
		else update(1 , 1 , n , 1 , i , 1);

		if(st[1].sml.A <= 2) ans += st[1].sml.B;
		if(st[1].sec.A <= 2) ans += st[1].sec.B;


		// int add = 0;
		// if(st[1].sml.A <= 2) add += st[1].sml.B;
		// if(st[1].sec.A <= 2) add += st[1].sec.B;
		// DB4(st[1].sml.A , st[1].sml.B , st[1].sec.A , st[1].sec.B);
		// DBGG("add = " , add);
		// print(1 , 1 , n);
		// return 0;
		// cout << endl ;
	}
	cout << ans - n << endl;
    return 0;
}