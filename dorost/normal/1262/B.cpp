#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int  N = 101234;
int a[N], b[N];
set <int> s;

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		s.clear();
		cin >> a[0];
		b[0] = a[0];
		for (int i = 1; i <= n; i++){
			s.insert(i);
		}
		s.erase(a[0]);
		for (int i = 1; i < n; i++) {
			cin >> a[i];
			if (a[i] == a[i - 1]){
				b[i] = *s.begin();
			}else
				b[i] = a[i];
			s.erase(b[i]);
		}
		bool f = true;
		int mx = b[0];
		for (int i = 1; i < n; i++){
			mx = max(mx, b[i]);
			if (mx != a[i])
				f = false;
		}
		if (!f){
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < n; i++){
			cout << b[i] << ' ';
		}
		cout << endl;
	}
}