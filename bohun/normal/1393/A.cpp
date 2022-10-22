#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n;
		scanf ("%d", &n);
		int m = (n + 1) / 2;
		if (n % 2 == 0)
			printf ("%d\n", m + 1);
		else 
			printf ("%d\n", m);
	}
	
	return 0;
}