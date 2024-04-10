/*input
3 1
1000000000 1000000000 1000000000
? 1 3 0
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
#define int int_fast64_t
#define MAX 100900
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , x[MAX] , tag[MAX * 4] , gi[MAX] , ni[MAX] , pre[MAX][6];

struct node{
	int x[6];
} s[MAX * 4];
node operator + (node a , node b){ 
	REP(i , 0 , 6) a.x[i] = (a.x[i] + b.x[i]) % mod;
	return a;
}
node operator * (node a , int  b){
	REP(i , 0 , 6) a.x[i] = (a.x[i] * b) % mod;
	return a;
}
node getone(int l , int r){ 
	node a;
	REP(i , 0 , 6) a.x[i] = pre[r][i] - pre[l - 1][i];
	return a;
}
void Push(int now , int l , int r){
	if(l != r && tag[now] != -1){
		s[ls] = getone(l , mid + 0) * tag[now];
		s[rs] = getone(mid + 1 , r) * tag[now];
		tag[ls] = tag[rs] = tag[now];
		tag[now] = -1;
	}
}
void update(int now , int l , int r , int ql , int qr , int val){
	if(ql <= l && r <= qr){
		s[now] = getone(l , r) * val;
		tag[now] = val;
	}
	else {
		Push(now , l , r);
		if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
		s[now] = s[ls] + s[rs];
	}
}
node query(int now , int l , int r , int ql , int qr){
	Push(now , l , r);
	if(ql <= l && r <= qr) return s[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return query(ls , l , mid + 0 , ql , qr) + query(rs , mid + 1 , r , ql , qr);
}
int C(int a , int b){ return gi[a] * ni[b] % mod * ni[a - b] % mod; }
int32_t main(){
	IOS;
	ni[0] = ni[1] = gi[0] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 1 , MAX) ni[i] = ni[i - 1] * ni[i] % mod;

	REP(i , 1 , MAX) pre[i][0] = 1;
	REP(i , 1 , MAX) REP(j , 1 , 6) pre[i][j] = pre[i][j - 1] * i % mod;
	REP(i , 1 , MAX) REP(j , 0 , 6) pre[i][j] = (pre[i][j] + pre[i - 1][j]) % mod;

	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) update(1 , 1 , n , i , i , x[i]);
	string s;
	int l , r , k;
	REP(i , 1 , m + 1){
		cin >> s >> l >> r >> k;
		if(s == "=") update(1 , 1 , n , l , r , k);
		if(s == "?"){
			int sum = 0 , type = 1 , res = 1;
			node tmp = query(1 , 1 , n , l , r);
			// REP(i , 0 , 6) cout << tmp.x[i] << " " ; cout << endl;
			RREP(j , k , 0){
				sum = (sum + C(k , j) * type * tmp.x[j] % mod * res) % mod;
				type = -type , res = res * (l - 1) % mod;
				sum = (sum % mod + mod) % mod;
			}
			cout << sum << endl;
		}
	}
    return 0;
}