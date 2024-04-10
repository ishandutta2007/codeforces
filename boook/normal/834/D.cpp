/*input
4 1
1 2 2 1
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
#define MAX 100000
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , x[MAX] , fr[MAX] , dp[MAX];
int big[MAX * 4] , tag[MAX * 4];
// dp[i][j] = dp[k][j - 1] + W(k + 1 , i);
void Build(int now , int l , int r){
	tag[now] = 0;
	if(l == r) big[now] = dp[l];
	else {
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
		big[now] = max(big[ls] , big[rs]);
	}
}
void Push(int now , int l , int r){
	if(l != r && tag[now]){
		tag[ls] += tag[now];
		tag[rs] += tag[now];
		big[ls] += tag[now];
		big[rs] += tag[now];
		tag[now] = 0;
	}
}
void update(int now , int l , int r , int ql , int qr , int val){
	Push(now , l , r);
	if(ql <= l && r <= qr){
		tag[now] ++;
		big[now] ++;
	}
	else {
		if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
		big[now] = max(big[ls] , big[rs]);
	}
}
int query(int now , int l , int r , int ql , int qr){
	Push(now , l , r);
	if(ql <= l && r <= qr) return big[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return max(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(j , 1 , m + 1){
		MEM(fr , 0);
		Build(1 , 0 , n);
		REP(i , 1 , n + 1){
			update(1 , 0 , n , fr[x[i]] , i - 1 , 1);
			// DB4("update" , fr[x[i]] + 1 , i , "");
			dp[i] = query(1 , 0 , n , 0 , i - 1);
			// DB4("dp[" , i , "] = " , dp[i]);
			fr[x[i]] = i;
		}
		// REP(i , 1 , n + 1) cout << dp[i] << " " ; cout << endl;
	}
	cout << dp[n] << endl;
    return 0;
}