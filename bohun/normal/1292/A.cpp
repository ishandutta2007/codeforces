#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i < n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 1e5 + 111;

int n, q;
int r, c;
int t[2][nax];
int bad = 0;

int main() {
	boost;
	cin >> n >> q;
	while(q--) {
		cin >> r >> c;
		r--;
		int R = (r ^ 1);
		t[r][c] ^= 1;
		for (int i = max(1, c - 1); i <= min(c + 1, n); ++i)
			if(t[R][i]) {
				if(t[r][c]) bad++;
				else bad--;
			}
		if(bad == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	
	return 0;
}