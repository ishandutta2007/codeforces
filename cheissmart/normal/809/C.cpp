#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 1e9 + 7;

int sum[32][2][2][2], ways[32][2][2][2];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

int solve(int a, int b, int k) {
	if(a == 0 || b == 0) return 0;
	memset(ways, 0, sizeof ways);
	memset(sum, 0, sizeof sum);
	a--, b--, k--;
	// sum of (x^y + 1) s.t. (0 <= x <= a && 0 <= y <= b)
	sum[31][0][0][0] = 0, ways[31][0][0][0] = 1;
	for(int i = 31; i >= 1; i--) {
		for(int fa = 0; fa < 2; fa++) {
			for(int fb = 0; fb < 2; fb++) {
				for(int fk = 0; fk < 2; fk++) {
					if(ways[i][fa][fb][fk] == 0) continue;
					for(int nowa = 0; nowa < 2; nowa++) {
						for(int nowb = 0; nowb < 2; nowb++) {
							int nowk = nowa ^ nowb;
							int new_fa = fa, new_fb = fb, new_fk = fk;
							int bita = a >> (i - 1) & 1, bitb = b >> (i - 1) & 1, bitk = k >> (i - 1) & 1;
							if(fa == 0 && bita < nowa) continue;
							if(fa == 0 && bita > nowa) new_fa = 1;
							if(fb == 0 && bitb < nowb) continue;
							if(fb == 0 && bitb > nowb) new_fb = 1;
							if(fk == 0 && bitk < nowk) continue;
							if(fk == 0 && bitk > nowk) new_fk = 1;
							add(ways[i - 1][new_fa][new_fb][new_fk], ways[i][fa][fb][fk]);
							add(sum[i - 1][new_fa][new_fb][new_fk], (sum[i][fa][fb][fk] * 2LL + ways[i][fa][fb][fk] * nowk) % M);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int fa = 0; fa < 2; fa++)
		for(int fb = 0; fb < 2; fb++)
			for(int fk = 0; fk < 2; fk++) {
				add(ans, sum[0][fa][fb][fk]);
				add(ans, ways[0][fa][fb][fk]);
			}
	return ans;
}

signed main()
{
	IO_OP;

	int q;
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		cout << (((ll) solve(x2, y2, k) - solve(x1 - 1, y2, k) - solve(x2, y1 - 1, k) + solve(x1 - 1, y1 - 1, k)) % M + M) % M << '\n';
	}

}