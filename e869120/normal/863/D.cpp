#include<iostream>
using namespace std;
#pragma warning(disable: 4996)
int n, q, m, a[200009], c1[200009], c2[200009], c3[200009], b[109];
int main() {
	cin >> n >> q >> m;
	for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); }
	for (int i = 1; i <= q; i++) { scanf("%d%d%d", &c1[i], &c2[i], &c3[i]); }
	for (int i = 1; i <= m; i++) { cin >> b[i]; }
	for (int i = q; i >= 1; i--) {
		if (c1[i] == 1) {
			for (int j = 1; j <= m; j++) {
				if (!(c2[i] <= b[j] && b[j] <= c3[i]))continue;
				if (b[j] == c2[i])b[j] = c3[i];
				else b[j]--;
			}
		}
		else {
			for (int j = 1; j <= m; j++) {
				if (!(c2[i] <= b[j] && b[j] <= c3[i]))continue;
				b[j] = c2[i] + c3[i] - b[j];
			}
		}
	}
	for (int i = 1; i <= m; i++) { if (i >= 2)printf(" "); printf("%d", a[b[i]]); }cout << endl;
	return 0;
}