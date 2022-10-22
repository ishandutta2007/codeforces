#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;		

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--) {
		int a;
		scanf ("%d", &a);
		vector <int> x;
		while (4 <= a) {
			x.pb(1);
			a -= 2;
		}
		if (a == 3) x.pb(7);
		if (a == 2) x.pb(1);
		
		reverse(x.begin(), x.end());
		for (auto it : x)
			printf ("%d", it);
		printf ("\n");
	}
		
	
	return 0;
}