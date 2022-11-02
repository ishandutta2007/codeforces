/*input
15 1
czaaawwwwwaaaa
3 8 5
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
#define MAX 200900
#define INF 0x3f3f3f3f
#define mod 1000000009LL
#define AC 10430579
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

struct node{ int val , siz; } st[MAX * 4];

int n , m , res[30] , pre[MAX] , h[MAX] = {1};
node pull(node a , node b){
	return node{ (a.val * b.siz + b.val) % mod , a.siz * b.siz % mod };
}
void build(int now , int l , int r){
	if(l == r) st[now] = node{l - pre[l] , AC};
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
string s;
vector<int> cc[30];
int solve(int l , int r){
	int val = query(1 , 0 , s.size() - 1 , l , r).val;
	REP(i , 0 , 26){
		auto to = lower_bound(ALL(cc[i]) , l);
		if(to != cc[i].end() && (*to) <= r){
			int idx = (*to) , tmp = idx - pre[idx];
			tmp = tmp * h[r - idx] % mod;
			val = (val + mod - tmp) % mod;
		}
	}
	return val;
}
int32_t main(){
	IOS;
	cin >> n >> m >> s;

	REP(i , 1 , s.size()) h[i] = h[i - 1] * AC % mod;
	REP(i , 0 , s.size()){
		pre[i] = res[s[i] - 'a'];
		res[s[i] - 'a'] = i;
		cc[s[i] - 'a'].pb(i);
	}
	// REP(i , 0 , s.size()) cout << i - pre[i] << " "; cout << endl;

	build(1 , 0 , s.size() - 1);
	REP(i , 1 , m + 1){
		int a , b , c;
		cin >> a >> b >> c , a -- , b --;
		if(solve(a , a + c - 1) == solve(b , b + c - 1)) 
			 cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}