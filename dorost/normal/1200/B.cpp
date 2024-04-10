#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 123;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool h = true;
		for (int i = 0; i < n - 1; i++){
			if (a[i] < a[i + 1] - k){
				m -= ((a[i + 1] - k) - a[i]);
			}else{
				m += min(a[i],a[i] - (a[i + 1] - k));
			}
			if (m < 0)
				h = false;
		}
		cout << (h ? "YES\n" : "NO\n");
	}
}