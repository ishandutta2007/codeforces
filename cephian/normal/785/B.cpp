#include <iostream>

using namespace std;

const int INF = 0x7fffffff;
int l1=-INF,r1=INF,l2=-INF,r2=INF;

int main() {
	ios::sync_with_stdio(0);
	int n,m,l,r;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> l >> r;
		l1 = max(l1,l);
		r1 = min(r1,r);
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> l >> r;
		l2 = max(l2,l);
		r2 = min(r2,r);
	}
	int k = max(l1-r2,l2-r1);
	if(k<0) k = 0;
	cout << k << "\n";
	return 0;
}