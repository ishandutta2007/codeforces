#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second
#define int long long
int dp[10000 * 1000 + 7];

int32_t main(){
	int an = 1;
	for (int i = 1; i < 1e7 + 7; i++){
		dp[i] = an;
		an += (i * 2 + 1);
	}
	int t = 1;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		if (n % 2 == k % 2 && n >= dp[k]){
			cout << "YES";
		}else
			cout << "NO";
		cout << endl;
	}
}