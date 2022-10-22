#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5 + 101;

int n;
int mex[N];
int ans[N];
vector <int> wolne;

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &mex[i]);
		if (mex[i] == mex[i - 1]) {
			wolne.pb(i);
			continue;
		}
		else {
			ans[i] = mex[i - 1];
			int g = mex[i] - mex[i - 1] - 1;
			if (g > ss(wolne)) {
				printf ("-1\n");
				return 0;
			}
			int liczba = mex[i - 1] + 1;
			while (g--) {
				ans[wolne.back()] = liczba++;
				wolne.pop_back();
			}
		}
	}
	while (ss(wolne)) {
		ans[wolne.back()] = 1e6;
		wolne.pop_back();
	}
	rep(i, 1, n)
		printf ("%d ", ans[i]);
	
		
	return 0;
}