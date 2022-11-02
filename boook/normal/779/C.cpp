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
#define int long long
#define MAX 200500
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	priority_queue<int , vector<int> , greater<int>> pq;
	int cnt = 0 , ans = 0;
	REP(i , 1 , n + 1){
		if(a[i] <= b[i]) cnt ++ , ans += a[i];
		else ans += b[i] , pq.push(a[i] - b[i]);
	}
	while(cnt < m) cnt ++ , ans += pq.top() , pq.pop();
	cout << ans << endl;
    return 0;
}