#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast ios::sync_with_stdio(false), cout.tie(), cin.tie();
#define sz(s) int(s.size())
const long long mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while (t--){
	int n;
	cin >> n;
	ll a[n], sum = 0;
	bool f = true;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		if(sum <= 0)
			f = false;
	}
	sum = 0;
	for (int i = n - 1; i >= 0; i--){
		sum += a[i];
		if(sum <= 0)
			f = false;
			//break;
	}
	cout << (f ? "YES" : "NO") << endl;
	}
}