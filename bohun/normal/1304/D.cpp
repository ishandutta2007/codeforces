#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

const int nax = 2e5 + 111;

int T;
vector <pair<int, int>> a, b;
int n;
char s[nax];
int r1[nax], r2[nax];

int main() {	
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		scanf ("%s", s + 1);
		a.clear();
		b.clear();
		for (int i = 1; i < n;) {
			int j = i;
			while (j < n && s[i] == s[j]) j++;
			int p = (i == 1 ? 1 : i + 1);
			int k = j;
			if (s[i] == '<') 
				a.pb({p, k});
			else 
				b.pb({p, k});
			i = j;
		}
		
		int val = n;
		per(j, 0, ss(a) - 1) 
			per(k, a[j].fi, a[j].se)
				r2[k] = val--;
				
		rep(j, 0, ss(b) - 1)
			rep(k, b[j].fi, b[j].se) 
				r2[k] = r1[k] = val--;
		
		val = n;
		rep(j, 0, ss(a) - 1)
			per(k, a[j].fi, a[j].se)
				r1[k] = val--;
			
		rep(i, 1, n)
			printf ("%d ", r1[i]);
		printf ("\n");
		rep(i, 1, n)
			printf ("%d ", r2[i]);
		printf("\n");
	}
	
	
	return 0;
}