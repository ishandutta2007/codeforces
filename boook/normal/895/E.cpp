/*input
10 10
1 2 3 4 5 6 7 8 9 10
2 1 5
1 1 5 6 10
1 1 5 6 10
1 1 3 6 9
2 1 3
1 5 7 8 10
1 1 1 10 10
2 1 5
2 7 10
2 1 10
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

double x[MAX] , sum[MAX * 4] , add[MAX * 4] , mul[MAX * 4];
void Push(int now , int l , int r){
	if(l != r){
		mul[ls] *= mul[now];
		add[ls] *= mul[now];
		sum[ls] *= mul[now];

		mul[rs] *= mul[now];
		add[rs] *= mul[now];
		sum[rs] *= mul[now];
		mul[now] = 1;

		add[ls] += add[now];
		sum[ls] += add[now] * (mid - l + 1);

		add[rs] += add[now];
		sum[rs] += add[now] * (r - (mid + 1) + 1);
		add[now] = 0;
	}
}
void update1(int now , int l , int r , int ql , int qr , double val){
	Push(now , l , r);
	if(ql <= l && r <= qr){
		mul[now] *= val;
		add[now] *= val;
		sum[now] *= val;
	}
	else{
		if(ql <= mid + 0) update1(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) update1(rs , mid + 1 , r , ql , qr , val);
		sum[now] = sum[ls] + sum[rs];
	}
}
void update2(int now , int l , int r , int ql , int qr , double val){
	Push(now , l , r);
	if(ql <= l && r <= qr){
		add[now] += val;
		sum[now] += val * (r - l + 1);
	}
	else{
		if(ql <= mid + 0) update2(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) update2(rs , mid + 1 , r , ql , qr , val);
		sum[now] = sum[ls] + sum[rs];
	}
}
double query(int now , int l , int r , int ql , int qr){
	Push(now , l , r);
	if(ql <= l && r <= qr) return sum[now];
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return query(ls , l , mid + 0 , ql , qr) + query(rs , mid + 1 , r , ql , qr);
}
int n , m;
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) update2(1 , 1 , n , i , i , x[i]);
	REP(i , 1 , m + 1){
		int ty , l , r , a , b;
		cin >> ty;
		if(ty == 1){
			cin >> l >> r >> a >> b;
			double tma = query(1 , 1 , n , l , r) , len1 = r - l + 1;
			double tmb = query(1 , 1 , n , a , b) , len2 = b - a + 1;
			update1(1 , 1 , n , l , r , (len1 - 1) / len1);
			update2(1 , 1 , n , l , r , tmb / len1 / len2);
			update1(1 , 1 , n , a , b , (len2 - 1) / len2);
			update2(1 , 1 , n , a , b , tma / len1 / len2);
		}
		else {
			cin >> l >> r;
			printf("%.11f\n", query(1 , 1 , n , l , r));
		}
	}
    return 0;
}