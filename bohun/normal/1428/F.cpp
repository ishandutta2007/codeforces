#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using ld = long double;
using namespace std;	

const int N = 5e5 + 500;

int n;
char s[N];
ll sum, res;
int cnt[N];

int main() {
	scanf ("%d%s", &n, s + 1);
	int ile = 0;
	rep(i, 1, n) {
		if (s[i] == '0') {
			rep(k, 0, ile) 
				cnt[k]++;
			res += sum;
			ile = 0;
		}
		else {
			sum += ile + 1;
			sum += cnt[ile];
			cnt[ile + 1] += cnt[ile];
			cnt[ile] = 0;
			ile++;
			res += sum;
		}
		//~ cat(res);
	}		
	printf ("%lld\n", res);
	return 0;
}