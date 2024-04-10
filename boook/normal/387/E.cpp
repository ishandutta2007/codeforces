#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 1000090
#define INF 0x3f3f3f3f

set<int> cc;
int n , k;
int to[MAX] , use[MAX];
int b[MAX];
void update(int from , int val){
	for(int i = from ; i < MAX ; i += i & -i)
		b[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from ; i > 0 ; i -= i & -i)
		cnt += b[i];
	return cnt;
}
int Find(int l , int r){
	return query(r) - query(l - 1);
}
typedef long long LL;
int32_t main(){
	IOS;
	cin >> n >> k;
	int tmp;
	REP(i , n) cin >> tmp , to[tmp] = i + 1;
	REP(i , k) cin >> tmp , use[tmp] = 1;
	cc.insert(0) , cc.insert(n + 1);
	REPNM(i , 1 , n + 1) update(i , 1);
	LL ans = 0;
	REPNM(i , 1 , n + 1){
		if(use[i]) cc.insert(to[i]) , update(to[i] , -1);
		else {
			auto q = cc.lower_bound(to[i]); q--;
			auto w = cc.upper_bound(to[i]);
			ans += LL(Find(*q + 1 ,  *w - 1));
			update(to[i] , -1);
		}
	}
	cout << ans << endl;
    return 0;
}