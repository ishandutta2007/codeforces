/*input
3
10
10
10
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 0 , n) cin >> x[i];
	REP(i , 0 , (1 << n)){
		int sum = 0;
		REP(j , 0 , n){
			if(i & (1 << j)) sum += x[j];
			else sum -= x[j];
		}
		if(sum % 360 == 0) return cout << "YES" << endl , 0;
	}
	cout << "NO" << endl;
    return 0;
}