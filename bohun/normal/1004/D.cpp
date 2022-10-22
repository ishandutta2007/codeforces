#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

const int nax = 1e6 + 111;

int n;
int cnt[nax];
int Max;
int ile[nax];
ll Sum;

bool solve(int row, int col, int x, int y) {
	FOR(i, 0, n)
		ile[i] = 0;
	FOR(i, 1, row)
		FOR(j, 1, col) {
			int odl = abs(x - i) + abs(y - j);
			ile[odl] += 1;
			if(ile[odl] > cnt[odl])
				return 0;
		}
	return 1;
}

ll Suma(int row, int col, int x, int y) {
	ll res = (ll) x * (x - 1) / 2 * col;
	res += (ll) (row - x + 1) * (row - x) / 2 * col;
	res += (ll) y * (y - 1) / 2 * row;
	res += (ll) (col - y + 1) * (col - y) / 2 * row;
	return res;
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) {
		int a;
		scanf("%d", &a);
		cnt[a] += 1;
		Max = max(Max, a);
		Sum += a;
	}
	for(int i = 1; i * i <= n; ++i) {
		if(n % i == 0) {
			int N = i;
			int M = n / N;
			int X = 1;
			int Y = 1;
			int K = Max;
			while(X < N && K) {
				X += 1;
				K -= 1;
			}
			while(K) {
				Y += 1;
				K -= 1;
			}
			while(X >= 1 && X <= N && Y >= 1 && Y <= M) {
				if(Sum == Suma(N, M, X, Y)) {
					if(solve(N, M, X, Y)) {
						printf("%d %d\n%d %d", N, M, X, Y);
						return 0;
					}
				}
				X -= 1;
				Y += 1;
			}
		}
	}
	printf("-1");
			
	
	
	
	
	
	return 0;
}