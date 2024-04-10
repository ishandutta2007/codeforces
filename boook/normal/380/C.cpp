/*input
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10
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
#define MAX 1000090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

string s;
struct node{ int sum , r , l; } st[MAX * 4];
node pull(node a , node b){
	int tmp = min(a.l , b.r);
	return node{a.sum + b.sum + tmp , a.r + b.r - tmp , a.l + b.l - tmp};
}
void build(int now , int l , int r){
	if(l == r){
		if(s[l - 1] == ')') st[now].r = 1;
		if(s[l - 1] == '(') st[now].l = 1;
	}
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		st[now] = pull(st[ls] , st[rs]);
	}
}
node query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return st[now];
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int m , ql , qr;
int32_t main(){
	IOS;
	cin >> s >> m;
	build(1 , 1 , s.size());
	REP(i , 1 , m + 1){
		cin >> ql >> qr;
		cout << (query(1 , 1 , s.size() , ql , qr).sum << 1) << endl;
	}
    return 0;
}