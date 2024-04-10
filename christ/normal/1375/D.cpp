#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	map<int,int> freq; set<int> out; int done = 0;
	for (int i = 1; i <= n; i++) {
		freq[a[i]]++;
		if (a[i] == i-1) ++done;
	}
	for (int i = 0; i <= n; i++) if (!freq.count(i)) out.insert(i);
	int ops = 0; vector<int> togo;
	while (done < n) {
		int mex = *out.begin(); ++ops; //printf ("done %d\n",done);
		if (mex == n) {
			int ind = -1, mn = 1e9;
			for (int i = 1; i <= n; i++) if (a[i] != i-1 && a[i] < mn) ind = i, mn = a[i];
			assert(~ind);
			if (!(--freq[a[ind]])) freq.erase(a[ind]), out.insert(a[ind]);
			else assert(0);
			a[ind] = mex; ++freq[mex];
			out.erase(mex); togo.push_back(ind);
		} else {
			if (!(--freq[a[mex+1]])) freq.erase(a[mex+1]), out.insert(a[mex+1]);
			a[mex+1] = mex; ++done; ++freq[mex];
			out.erase(mex); togo.push_back(mex+1);
		}
	}
	assert(ops <= 2 * n);
	printf ("%d\n",ops);
	for (int i : togo) printf ("%d ",i);
	printf ("\n");
}

int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}

// - + - + - + - +
/*
2 0 1 1 2 4 4 2 0
2 0 1 3 2 4 4 2 0
2 0 1 3 2 5 4 2 0
2 0 1 3 2 5 6 2 0
2 0 1 3 4 5 6 2 0
2 0 1 3 4 5 6 7 0
2 0 1 3 4 5 6 7 8
2 9 1 3 4 5 6 7 8
0 9 1 3 4 5 6 7 8
0 9 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8
*/