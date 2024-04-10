#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

int mod (int x, int m){
	if (x < 0){
		return ((m) - (-x % m) == m ? 0 : m - (-x % m));
	}else
		return x % m;
}

int32_t main(){
	int t;
	scanf("%lld", &t);
	while (t--){
		int n;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++){
			scanf("%lld", &a[i]);
			a[i] = mod((a[i] + i), n);
		}
		sort (a, a + n);
		bool f = true;
		for (int i = 0; i < n; i++){
			if (i != a[i])
				f = false;
			//			cout << a[i] << ' ';
		}
		//		cout << endl;
		printf((f ? "YES\n" : "NO\n"));
	}
}