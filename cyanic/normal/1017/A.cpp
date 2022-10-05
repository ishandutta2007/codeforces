#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 100005;
struct node {
	int val, id;
	bool operator < (const node &x) const {
		return val > x.val || val == x.val && id < x.id;
	}
} x[maxn];
int n, a, b, c, d;

int main() {
	cin >> n;
	rep (i, 1, n) {
		cin >> a >> b >> c >> d;
		x[i].id = i;
		x[i].val = a + b + c + d;
	}
	sort(x + 1, x + n + 1);
	rep (i, 1, n)
		if (x[i].id == 1) cout << i << endl;
	
	return 0;
}