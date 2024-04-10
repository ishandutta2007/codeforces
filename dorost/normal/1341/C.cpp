#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], n, x;
bool f;

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		f = true;
		for (int i = 0; i <= n + 10; i++){
			a[i] = 0;
		}
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int lst = n;
		for (int i = 0; i < n; i++){
			int x = i;
			while (a[i] + 1 == a[i + 1]){
				i ++;
			}
			if (a[i] == lst){
				for (int j = i; j >= x; j--){
					if (a[j] == lst)
						lst = a[j] - 1;
				}
			}else
				f = false;// cout << x << ' ' << i << ' ' << a[x] << ' ' << a[i] << endl;
//			cout << lst << endl;
		}
		printf((f ? "YES\n" : "NO\n"));
	}
}