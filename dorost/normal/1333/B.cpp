#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100123;
int a[N], b[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int x = n + 10, y = n + 10;
		bool f = true, h = true;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] < 0 && f){
				x = i;
				f = false;
			}
			if (a[i] > 0 && h){
				y = i;
				h = false;
			}
		}
		f = true;
		for (int i = 0; i < n; i++){
			cin >> b[i];
			if ((b[i] < a[i] && i > x) || (b[i] > a[i] && i > y) || b[i] == a[i]);else{
				f = false;
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
}