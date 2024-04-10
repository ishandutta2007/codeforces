#include <bits/stdc++.h>

const int MAXN = 300010;
typedef long long LL;
typedef long double LD;
int ks[MAXN], hav, top;
LL bs[MAXN], db, dx;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q; std::cin >> hav >> Q; top = 1;
	while (Q --> 0) {
		int opt, x, y;
		std::cin >> opt >> x;
		if (opt == 1) {
			top = 1, db = dx = ks[1] = bs[1] = 0; hav += x;
		} else if (opt == 2) {
			*ks = hav, hav += x, *bs = -((LL) dx * *ks + db);
			while (top > 1) {
				LD d = (LD) (bs[top] - bs[top - 1]) * (*ks - ks[top]);
				d -= (LD) (*bs - bs[top]) * (ks[top] - ks[top - 1]);
				if (d < -1e-5) break;
				--top;
			}
			++top, ks[top] = *ks, bs[top] = *bs;
		} else {
			std::cin >> y, dx += y, db += x;
		}
		while (top > 1) {
			LD v1 = bs[top - 1] + ks[top - 1] * dx;
			LD v2 = bs[top] + ks[top] * dx;
			if (v1 > v2) break;
			--top;
		}
		std::cout << ks[top] + 1 << ' ' << (LL) ks[top] * dx + bs[top] + db << '\n';
	}
	return 0;
}