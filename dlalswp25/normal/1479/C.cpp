#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int L, R;
vector<pair<pii, int> > ans;
int N;

void add(int a, int b, int c) {
	ans.emplace_back(pii(a, b), c);
}

void print() {
	if(L != 1) {
		N++;
		add(N - 1, N, L - 1);
	}
	puts("YES");
	printf("%d %d\n", N, ans.size());
	for(auto& i : ans) printf("%d %d %d\n", i.first.first, i.first.second, i.second);
}

int main() {
	scanf("%d%d", &L, &R);
	int X = R - L + 1;

	if(X == 1) {
		N = 2; add(1, 2, 1);
		print(); return 0;
	}
	if(X == 2) {
		N = 4;
		add(1, 4, 1);
		add(1, 3, 1);
		add(3, 4, 1);
		print(); return 0;
	}
	if(X == 3) {
		N = 4;
		add(1, 4, 1);
		add(1, 3, 1);
		add(1, 2, 1);
		add(2, 3, 1);
		add(3, 4, 1);
		print(); return 0;
	}
	if(X == 4) {
		N = 4;
		add(1, 2, 2);
		add(2, 3, 1);
		add(3, 4, 1);
		add(1, 3, 1);
		add(1, 4, 1);
		add(2, 4, 1);
		print(); return 0;
	}

	N = 7;
	int tmp = X;
	while(tmp > 20) {
		tmp = (tmp - 1) / 4;
		N += 3;
	}

	add(N - 3, N - 2, 2);
	add(N - 2, N - 1, 1);
	add(N - 1, N, 1);
	add(N - 3, N - 1, 1);
	add(N - 2, N, 1);
	add(N - 3, N, 1);

	int t = 1;
	while(X > 4) {
		if(X <= 20) {
			if(X <= 8) {
				add(t - 1 + 1, t - 1 + 4, 1);
				if(X == 6) add(t - 1 + 1, t - 1 + 6, 5);
				if(X == 7) add(t - 1 + 1, t - 1 + 5, 5);
				if(X == 8) {
					add(t - 1 + 1, t - 1 + 5, 5);
					add(t - 1 + 1, t - 1 + 6, 7);
				}
			}
			else if(X <= 12) {
				add(t - 1 + 1, t - 1 + 4, 1);
				add(t - 1 + 1, t - 1 + 3, 4);
				add(t - 1 + 3, t - 1 + 4, 1);
				if(X == 10) add(t - 1 + 1, t - 1 + 6, 9);
				if(X == 11) add(t - 1 + 1, t - 1 + 5, 9);
				if(X == 12) {
					add(t - 1 + 1, t - 1 + 5, 9);
					add(t - 1 + 1, t - 1 + 6, 11);
				}
			}
			else if(X <= 16) {
				add(t - 1 + 1, t - 1 + 4, 1);
				add(t - 1 + 1, t - 1 + 2, 4);
				add(t - 1 + 2, t - 1 + 3, 4);
				add(t - 1 + 3, t - 1 + 4, 1);
				add(t - 1 + 1, t - 1 + 3, 4);
				if(X == 14) add(t - 1 + 1, t - 1 + 6, 13);
				if(X == 15) add(t - 1 + 1, t - 1 + 5, 13);
				if(X == 16) {
					add(t - 1 + 1, t - 1 + 5, 13);
					add(t - 1 + 1, t - 1 + 6, 15);
				}
			}
			else {
				add(t - 1 + 1, t - 1 + 4, 1);
				add(t - 1 + 1, t - 1 + 2, 4);
				add(t - 1 + 2, t - 1 + 3, 4);
				add(t - 1 + 3, t - 1 + 4, 1);
				add(t - 1 + 1, t - 1 + 3, 4);
				add(t - 1 + 2, t - 1 + 4, 9);
				if(X == 18) add(t - 1 + 1, t - 1 + 6, 17);
				if(X == 19) add(t - 1 + 1, t - 1 + 5, 17);
				if(X == 20) {
					add(t - 1 + 1, t - 1 + 5, 17);
					add(t - 1 + 1, t - 1 + 6, 19);
				}
			}
			add(t - 1 + 1, t - 1 + 7, 1);

			X = 4;
			continue;
		}

		int k = (X - 1) / 4;
		add(t - 1 + 1, t - 1 + 4, 1);
		add(t - 1 + 1, t - 1 + 2, k);
		add(t - 1 + 2, t - 1 + 3, k);
		add(t - 1 + 3, t - 1 + 4, 1);
		add(t - 1 + 1, t - 1 + 3, k);
		add(t - 1 + 2, t - 1 + 4, 2 * k + 1);
		if(X == k * 4 + 2) add(t - 1 + 1, N - 1, 4 * k + 1);
		if(X == k * 4 + 3) add(t - 1 + 1, N - 2, 4 * k + 1);
		if(X == k * 4 + 4) {
			add(t - 1 + 1, N - 2, 4 * k + 1);
			add(t - 1 + 1, N - 1, 4 * k + 3);
		}
		add(t, N, 1);

		X = k;
		t += 3;
	}

	print();

	return 0;
}