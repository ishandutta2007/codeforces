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

int h[100005];

int main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m;
	vector<vi> a(n, vi(m)), f(n, vi(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	cin >> k;
	for(int j=0;j<m;j++) {
		f[n-1][j] = n-1;
		for(int i=n-2;i>=0;i--) {
			if(a[i][j] <= a[i+1][j]) f[i][j] = f[i+1][j];
			else f[i][j] = i;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			h[i] = max(h[i], f[i][j]);
	while(k--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if(h[l] >= r)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
}