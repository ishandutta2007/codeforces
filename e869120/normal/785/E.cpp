#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>x[1200]; int n, q, a, b, c[210000], p = 800; long long cnt = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { c[i] = i; x[i / p].push_back(i); }
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b; a--; b--; if (a > b)swap(a, b);
		int F1 = c[a], F2 = c[b]; if (F1 > F2)swap(F1, F2);
		
		int G1 = (a + p - 1) / p, G2 = b / p;
		int H1 = G1*p, H2 = G2*p;

		int R = 0;
		if (G1 > G2) {
			for (int j = a; j <= b; j++) {
				if (F1 < c[j] && c[j] < F2)R++;
			}
		}
		else {
			for (int j = G1; j < G2; j++) {
				int pos1 = lower_bound(x[j].begin(), x[j].end(), F1 + 1) - x[j].begin();
				int pos2 = lower_bound(x[j].begin(), x[j].end(), F2) - x[j].begin();
				R += (pos2 - pos1);
			}
			for (int j = a; j < H1; j++) { if (F1 < c[j] && c[j] < F2)R++; }
			for (int j = H2; j < b; j++) { if (F1 < c[j] && c[j] < F2)R++; }
		}
		R *= 2; R++;
		if (c[a] < c[b])cnt += R; if (c[a] > c[b]) cnt -= R;
		cout << cnt << endl;

		int B1 = a / p, B2 = b / p;
		if (B1 != B2) {
			for (int i = 0; i < x[B1].size(); i++) {
				if (x[B1][i] == c[a])x[B1][i] = c[b];
			}
			for (int i = 0; i < x[B2].size(); i++) {
				if (x[B2][i] == c[b])x[B2][i] = c[a];
			}
			sort(x[B1].begin(), x[B1].end());
			sort(x[B2].begin(), x[B2].end());
		}
		swap(c[a], c[b]);
	}
	return 0;
}