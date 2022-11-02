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
#define mid (l + r >> 1)

int n , m , x[MAX] , sml[MAX * 4];
vector<int> uni;
void update(int now , int l , int r , int k , int val){
	if(l == r) sml[now] += val/* , DB4("the " , k , "change = " , val)*/;
	else {
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		sml[now] = INF;
		if(sml[ls]) sml[now] = min(sml[now] , sml[ls]);
		if(sml[rs]) sml[now] = min(sml[now] , sml[rs]);
	}
}
void query(int now , int l , int r){
	if(l == r) return cout << uni[l] << endl , void();
	if(sml[rs] == 1) return query(rs , mid + 1 , r) , void();
	if(sml[ls] == 1) return query(ls , l , mid + 0) , void();
	cout << "Nothing" << endl;
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) uni.pb(x[i]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 1 , n + 1) x[i] = lower_bound(ALL(uni) , x[i]) - uni.begin();
	REP(i , 1 , m) update(1 , 0 , uni.size() - 1 , x[i] , 1);
	REP(i , m , n + 1){
		update(1 , 0 , uni.size() - 1 , x[i] , 1);
		// DBGG("now = " , sml[1]);
		query(1 , 0 , uni.size() - 1);
		update(1 , 0 , uni.size() - 1 , x[i - m + 1] , -1);
	}
    return 0;
}