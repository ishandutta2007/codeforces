#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int a[3];

int main() {
	int T = read();
	while (T--) {
		a[0] = read(); a[1] = read(); a[2] = read();
		int ansa = -1, ansb = -1, ansc = -1;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++) {
					int ca = a[i], cb = a[j], cc = a[k];
					if (a[0] == max(ca, cb) && a[1] == max(ca, cc) && a[2] == max(cb, cc)) {
						ansa = ca, ansb = cb, ansc = cc; break;
					}
				}
		if (ansa != -1 && ansb != -1 && ansc != -1) puts("YES"), printf("%d %d %d\n", ansa, ansb, ansc);
		else puts("NO");
	} 
	return 0;
}