#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;

using namespace std;

const int N = 55;

int T;
int t[2];
char s[N];
vector <int> c;

int main() {
	scanf("%d", &T);
	while(T--) {
		int n;
		c.clear();
		t[0] = t[1] = 0;
		scanf("%d", &n);
		FOR(i, n) {
			scanf("%s", s + 1);
			int m = strlen(s + 1);
			FOR(j, m) {
				t[s[j] - '0'] += 1;
			}
			c.pb((m) / 2);
		}
		int mam = t[0] / 2 + t[1] / 2;
		int ans = 0;
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());
		while(ss(c) && c.back() <= mam) {
			mam -= c.back();
			c.pop_back();
			ans += 1;
		}
		printf("%d\n", ans);
	}
			
				
	
	return 0;
}