#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2333;
int n, m, c, a[MaxN];
int main() {
	int i, t = 0;
	cin >> n >> m >> c;
	while(m--) {
		int x, i; cin >> x;
		if(x * 2 <= c) 
			for(i = 1; a[i] && a[i] <= x; i++);
		else 
			for(i = n; a[i] && a[i] >= x; i--);
		t += !a[i]; a[i] = x; cout << i << endl; if(t == n) break;
	}

	return 0;
}