#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[2005][2005], ans[2005][2005], g;
int n, k;
pi r[2005], c[2005];

void updc(int j, int i, int& ct, int d = 1) {
	if(c[j].F) {
		if(i <= c[j].F && c[j].F <= i+k-1 && i <= c[j].S && c[j].S <= i+k-1)
			ct+=d;
	}
}

void updr(int i, int j, int& ct, int d = 1) {
	if(r[i].F) {
		if(j <= r[i].F && r[i].F <= j+k-1 && j <= r[i].S && r[i].S <= j+k-1)
			ct+=d;
	}
}
int main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			char c;
			cin >> c;
			if(c == 'B')
				a[i][j] = 1;
		}
	for(int i=1;i<=n;i++) {
		int mn = INF, mx = -INF;
		for(int j=1;j<=n;j++)
			if(a[i][j]) {
				mn = min(mn, j);
				mx = max(mx, j);
			}
		if(mn == INF) g++;
		if(mn != INF && mx-mn+1 <= k)
			r[i] = {mn, mx};
	}
	for(int j=1;j<=n;j++) {
		int mn = INF, mx = -INF;
		for(int i=1;i<=n;i++)
			if(a[i][j]) {
				mn = min(mn, i);
				mx = max(mx, i);
			}
		if(mn == INF) g++;
		if(mn != INF && mx-mn+1 <= k)
			c[j] = {mn, mx};
	}
	for(int i=1;i<=n-k+1;i++) {
		int ct = 0;
		for(int j=1;j<=k;j++) {
			updc(j, i, ct);
		}
		ans[i][1] += ct;
		for(int j=k+1;j<=n;j++) {
			int jj = j - k + 1;
			updc(j, i, ct);
			updc(jj-1, i, ct, -1);
			ans[i][jj] += ct;
		}
	}
	for(int j=1;j<=n-k+1;j++) {
		int ct = 0;
		for(int i=1;i<=k;i++) {
			updr(i, j, ct);
		}
		ans[1][j] += ct;
		for(int i=k+1;i<=n;i++) {
			int ii = i - k + 1;
			updr(i, j, ct);
			updr(ii-1, j, ct, -1);
			// cout << ii << ", "  << j << " "<< ct << endl;
			ans[ii][j] += ct;
		}
	}
	int mx = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mx=  max(mx, ans[i][j]);
	cout << mx + g << endl;
}