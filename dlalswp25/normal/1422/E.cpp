#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char A[101010];
vector<pii> v;

bool sh[101010];
int rgt[101010];
int lft[101010];

int D[101010];

int main() {
	scanf("%s", A + 1);
	N = strlen(A + 1);

	int bef = 1;
	v.emplace_back(0, 0);
	for(int i = 2; i <= N + 1; i++) {
		if(A[i] != A[i - 1]) {
			v.emplace_back((int)A[i - 1] - 'a', i - bef);
			bef = i;
		}
	}

	M = (int)v.size() - 1;

	int lst = -1, lst2 = -1, idx = M + 1;
	for(int i = M; i >= 1; i--) {
		rgt[i] = idx;
		if(v[i].first > lst) {
			sh[i] = true;
			if(v[i].second & 1) {
				lft[idx] = i; idx = i;
				lst2 = lst; lst = v[i].first;
			}
		}
		else if(v[i].first == lst) {
			if(v[i].first < lst2) {
				lft[idx] = i; idx = i;
			}
			else {
				sh[i] = true;
				if(v[i].second & 1) {
					lft[idx] = i; idx = i;
				}
			}
		}
		else {
			lft[idx] = i; idx = i;
			lst2 = lst; lst = v[i].first;
		}
	}

	for(int i = M; i >= 1; i--) {
		if(sh[i]) D[i] = D[i + 1] + (v[i].second & 1);
		else D[i] = D[i + 1] + v[i].second;
	}

	int ans = D[1];
	int p = 1;

	for(int i = 1; i <= N; i++) {
		int ans = D[p + 1];
		if(sh[p]) ans += v[p].second & 1;
		else ans += v[p].second;

		printf("%d ", ans);
		if(ans <= 10) {
			int x = p;
			while(x <= M) {
				int it = sh[x] ? v[x].second & 1 : v[x].second;
				for(int j = 0; j < it; j++) printf("%c", v[x].first + 'a');
				x = rgt[x];
			}
			puts("");
		}
		else {
			int cnt = 0;
			int x = p;
			while(x <= M) {
				int it = sh[x] ? v[x].second & 1 : v[x].second;
				for(int j = 0; j < it; j++) {
					printf("%c", v[x].first + 'a');
					cnt++;
					if(cnt >= 5) break;
				}
				x = rgt[x];
				if(cnt >= 5) break;
			}

			printf("...");
			x = lft[M + 1];
			vector<char> tmp;
			cnt = 0;
			while(x > 0) {
				int it = sh[x] ? v[x].second & 1 : v[x].second;
				for(int j = 0; j < it; j++) {
					tmp.push_back(v[x].first + 'a');
					cnt++;
					if(cnt >= 2) break;
				}
				x = lft[x];
				if(cnt >= 2) break;
			}

			printf("%c%c\n", tmp[1], tmp[0]);
		}

		v[p].second--;
		if(!v[p].second) p++;
	}

	return 0;
}