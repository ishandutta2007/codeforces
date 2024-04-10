/*input
2
2 2
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mid (l + r >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , ans , x[MAX] , p[MAX];
int sum[MAX * 4] , tag[MAX * 4];
void push(int now , int l , int r){
	if(tag[now] == 0) return ;
	sum[ls] += tag[now] * ((mid + 0) - l + 1);
	sum[rs] += tag[now] * (r - (mid + 1) + 1);
	tag[ls] += tag[now];
	tag[rs] += tag[now];
	tag[now] = 0;
}
void update(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) tag[now] ++ , sum[now] += r - l + 1;
	else{
		push(now , l , r);
		if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr);
		if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr);
		sum[now] = sum[ls] + sum[rs];
	}
}
inline int rit(){
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
	return res;
}
int32_t main(){
	n = rit();
	REP(i , 1 , n + 1) x[i] = rit();
	REP(i , 1 , n + 1){
		update(1 , 1 , n , p[x[i]] + 1 , i) , ans += sum[1] + sum[1] - 1;
		p[x[i]] = i;
	}
	printf("%.11f\n", (double)ans / n / n);
    return 0;
}