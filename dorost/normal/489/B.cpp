#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 100123;
int a[N], b[N];
bool f[N];

int32_t main(){
	int n, m, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort (a, a + n);
	sort (b, b + m);
//	for (int i = 0; i < n; i++)
//		cout << a[i] << ' ';
//	cout << endl;
//	for (int i = 0; i < m; i++)
//		cout << b[i] << ' ';
//	cout << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (f[j])
				continue;
			if (abs(a[i] - b[j]) <= 1){
				f[j] = true, ans++;
//				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
	cout << ans;
}