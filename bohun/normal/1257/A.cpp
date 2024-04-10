#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

int n;
int T;
int x;
int a;
int b;
 
int main() {	
	scanf("%d", &T);
	FOR(i, T) {
		scanf("%d %d %d %d", &n, &x, &a, &b);
		if(a > b)
			swap(a, b);
		int res = b - a;
		int odl = n - b;
		int wal = min(x, odl);
		res += wal;
		x -= wal;
		odl = a - 1;
		wal = min(x, odl);
		res += wal;
		printf("%d\n", res);
	}
	
	
	return 0;
}