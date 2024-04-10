#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, M = 1e6+3;

int a[20][20];

int qry(int x, int ans=0) {
	cout << "? " << x << endl;
	cin >> ans;
	return ans;
}

void extgcd(int a, int &x, int b, int &y, int &g) {
	if(b == 0) {
		g = a;
		x = 1, y = 0;
	} else {
		extgcd(b, y, a%b, x, g);
		y -= a/b*x;
	}
}

int inv(int i) {
	int x, y, g;
	extgcd(i, x, M, y, g);
	return x;
}

int f(int x) {
	int p = 1, ans = 0;
	for(int i=0;i<11;i++) {
		ans = (ans + p * a[i][11]) % M;
		p = p * x % M;
	}
	return ans;
}

int32_t main()
{
	IO_OP;
	
	for(int i=0;i<11;i++) {
		a[i][0] = 1;
		for(int j=1;j<11;j++) {
			a[i][j] = a[i][j-1] * i % M;
		}
		a[i][11] = qry(i);
	}
	for(int i=0;i<11;i++) {
		int invx = inv(a[i][i]);
		for(int j=0;j<12;j++)
			a[i][j] = a[i][j] * invx % M;
		for(int j=0;j<11;j++) {
			if(i != j) {
				int m = -a[j][i];
				for(int k=0;k<12;k++) {
					a[j][k] = (a[j][k] + a[i][k] * m % M) % M;
				}
			}
		}
	}
	for(int i=0;i<M;i++) {
		if(f(i) == 0) {
			cout << "! " << i << endl;
			return 0;
		}
	}
	cout << "! -1" << endl;
}