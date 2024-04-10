/*input
6
2 1 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///-----------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX];
deque<int> dq;
int32_t main(){
	IOS;
	cin >> n , n >>= 1;
	REP(i , 1 , n + 1) cin >> x[i];
	dq.push_back(  		x[n] / 2);
	dq.push_back(x[n] - x[n] / 2);
	RREP(i , n - 1 , 1){
		int v1 = x[i] / 2;
		int v2 = x[i] - v1;
		if(dq.front() < v1){
			int val = v1 - dq.front();
			v1 -= val;
			v2 += val;
		}
		if(v2 < dq.back()){
			int val = dq.back() - v2;
			v1 -= val;
			v2 += val;
		}
		dq.push_front(v1);
		dq.push_back(v2);
	}
	for(auto to : dq) cout << to << " " ; cout << endl;
    return 0;
}