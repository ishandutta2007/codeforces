#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define int long long
 
using namespace std;	

int ask(int x) {
	printf ("%lld\n", x);
	fflush(stdout);
	int y;
	scanf ("%lld", &y);
	if (!y) exit(0);
	return y - 1;
}

vector <int> t(3);

int magic() {
	vector <int> g = t;
	sort(all(g));
	return g[2] + g[2] - g[1] - g[0];
}
 
int32_t main() {
	scanf ("%lld%lld%lld", &t[0], &t[1], &t[2]);
	printf ("First\n");
	fflush(stdout);
	
	int M = magic();
	int kto = ask(M);
	
	if (t[kto] >= max({t[0], t[1], t[2]})) {
		// problem?
		t[kto] += M;
		
		M = magic();
		kto = ask(M);
		t[kto] += M;
		
		sort(all(t));
		ask(t[1] - t[0]);
	}
	else {
		t[kto] += M;
		sort(all(t));
		ask(t[1] - t[0]);
	}
	
	return 0;
}