#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define int long long
int t , n , a;
int solve(){
	// cout << "here" << n - a << endl;
	if(n - a != 1) return 0;
	int tmp = n + a;
	REP(i , 2 , tmp + 1){
		if(i * i > tmp) break;
		if(tmp % i == 0){
			// cout << "now = " << i << endl;
			return 0;
		}
	}
	return 1;
}
int32_t main(){
	cin >> t;
	REP(tiems , 0 , t){
		cin >> n >> a;
		if(solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}