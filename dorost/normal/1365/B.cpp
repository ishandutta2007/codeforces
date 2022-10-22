/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long 
const int N = 505;
int a[N], b[N];
pair <int, int> c[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		bool f = false, h = false;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++){
			cin >> b[i];
			if (b[i] == 1)
				f = true;
			else
				h = true;
		}
		cout << ((f && h) || is_sorted(a, a + n) ? "Yes" : "No") << endl;
	}
}