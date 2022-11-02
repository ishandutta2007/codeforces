/*input
3 4
2 2 3
1 1
1 2
2 4
3 6
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
///-----------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

int n , m , x[MAX] , sum[MAX * 4];

void build(int now , int l , int r){
	if(l == r) sum[now] = x[l];
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		sum[now] = sum[ls] + sum[rs];
	}
}
void update(int now , int l , int r , int k , int val){
    if(l == r) sum[now] = val;
    else {
        if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
        if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		sum[now] = sum[ls] + sum[rs];
    }
}
int query(int now , int l , int r , int k){
    if(l == r) return sum[now];
    else if(k <= mid + 0) return query(ls , l , mid + 0 , k);
    else if(mid + 1 <= k) return query(rs , mid + 1 , r , k) + sum[ls];
}
PII lowerbound(int now , int l , int r , int val){
    if(l == r) return mp(l , val - sum[now]);
    else {
        if(val > sum[ls])
        	 return lowerbound(rs , mid + 1 , r , val - sum[ls]);
        else return lowerbound(ls , l , mid + 0 , val);
    }
}
inline int rit(){
	char c = getchar();
	int val = 0;
	while(isdigit(c) == 0) c = getchar();
	while(isdigit(c) == 1) val = (val << 1) + (val << 3) + c - '0' , c = getchar();
	return val;
}
int32_t main(){
    n = rit() , m = rit();
    REP(i , 1 , n + 1) x[i] = rit();
    build(1 , 0 , n);
    // return 0;
    REP(i , 1 , m + 1){
        int idx = rit() , val = rit() , now = 1 , ans = -1;
        update(1 , 0 , n , idx , val);
        val = query(1 , 0 , n , now);
        while(now <= n){
            if(query(1 , 0 , n , now - 1) * 2 == val){
                ans = now;
                break;
            }
            else {
            	if(sum[1] < val * 2) break;
                PII tmp = lowerbound(1 , 0 , n , val * 2);
                now = tmp.A , val = val + val - tmp.B;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}