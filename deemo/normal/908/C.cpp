#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, r;
int x[MAXN];
ld y[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> x[i];

		y[i] = r;
		for (int j = 0; j < i; j++) {
			int dist = abs(x[i] - x[j]);
			if (dist > 2*r) continue;

			ld yy = sqrt(4*r*r - dist*dist);
			y[i] = max(y[i], yy+y[j]);
		}
	}
	cout << fixed << setprecision(11);
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << "\n";
	return 0;
}