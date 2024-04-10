#include<bits/stdc++.h>
typedef long long ll;

int q;

int main() {
	scanf("%d", &q);
	while (q--) {
		int u, v, cntu = 0, cntv = 0; scanf("%d%d", &u, &v);
		if (u > v) { printf("NO\n"); continue; }
		bool flg = 1;
		for (int i = 0; i < 30; i++) {
			cntu += (u >> i) & 1;
			cntv += (v >> i) & 1;
			if (cntu < cntv) flg = 0;
		}
//		cntu = 0;
//		cntv = 0;
//		for (int i = 29; i >= 0; i--) {
//			cntu += (u >> i) & 1;
//			cntv += (v >> i) & 1;
//			if (cntu > cntv) flg = 0;
//		}
		if (flg) printf("YES\n");
		else printf("NO\n");
	}
}