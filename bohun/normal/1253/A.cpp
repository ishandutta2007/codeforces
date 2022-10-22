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

const int nax = 100005;

int T;
int n;
int a[nax], b[nax], c[nax], s;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		s = 0;
		FOR(i, n) scanf("%d", a + i);
		FOR(i, n) scanf("%d", b + i);
		bool bad = 0;
		FOR(i, n) {
			c[i] = a[i] - b[i];
			if(c[i] > 0)
				bad = 1;
			if(c[i] != 0)
				s += 1;
			if(c[i] != 0 && c[i - 1] == 0 && s > 1)
				bad = 1;
			if(c[i] != 0 && c[i - 1] != 0 && c[i] != c[i - 1])
				bad = 1;
		}
		if(bad)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	
	return 0;
}