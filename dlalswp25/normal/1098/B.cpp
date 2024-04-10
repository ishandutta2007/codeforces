#include <bits/stdc++.h>

using namespace std;

string s[300005];
string ans[300005];
char c1[300005][2];
char c2[2][300005];

int od[4][300005];
int ev[4][300005];
int N, M;

int cv(char x) {
	if(x == 'A') return 0;
	if(x == 'C') return 1;
	if(x == 'G') return 2;
	if(x == 'T') return 3;
}
char rv(int x) {
	if(x == 0) return 'A';
	if(x == 1) return 'C';
	if(x == 2) return 'G';
	if(x == 3) return 'T';
}

void f() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(j & 1) od[cv(s[i][j])][i]++;
			else ev[cv(s[i][j])][i]++;
		}
	}
}

void g() {
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(j & 1) od[cv(s[j][i])][i]++;
			else ev[cv(s[j][i])][i]++;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++) cin >> s[i];

	f();

	int mx = 0;

	int mat = 0;
	vector<int> V;
	V.push_back(0);
	V.push_back(1);
	V.push_back(2);
	V.push_back(3);
	for(int i = 0; i < 24; i++) {
		mat = 0;
		for(int j = 0; j < N; j++) {
			if(j % 2 == 0) {
				if(ev[V[0]][j] + od[V[1]][j] < ev[V[1]][j] + od[V[0]][j]) {
					c1[j][0] = rv(V[1]), c1[j][1] = rv(V[0]);
					mat += ev[V[1]][j] + od[V[0]][j];
				}
				else {
					c1[j][0] = rv(V[0]), c1[j][1] = rv(V[1]);
					mat += ev[V[0]][j] + od[V[1]][j];
				}
			}
			else {
				if(ev[V[2]][j] + od[V[3]][j] < ev[V[3]][j] + od[V[2]][j]) {
					c1[j][0] = rv(V[3]), c1[j][1] = rv(V[2]);
					mat += ev[V[3]][j] + od[V[2]][j];
				}
				else {
					c1[j][0] = rv(V[2]), c1[j][1] = rv(V[3]);
					mat += ev[V[2]][j] + od[V[3]][j];
				}
			}
		}

		if(mat > mx) {
			for(int i = 0; i < N; i++) {
				ans[i].clear();
				for(int j = 0; j < M; j++) {
					ans[i].push_back(c1[i][j % 2]);
				}
			}
			mx = mat;
		}

		next_permutation(V.begin(), V.end());
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 300005; j++) {
			od[i][j] = ev[i][j] = 0;
		}
	}

	g();
	V.clear();

	V.push_back(0);
	V.push_back(1);
	V.push_back(2);
	V.push_back(3);
	for(int i = 0; i < 24; i++) {
		mat = 0;
		for(int j = 0; j < M; j++) {
			if(j % 2 == 0) {
				if(ev[V[0]][j] + od[V[1]][j] < ev[V[1]][j] + od[V[0]][j]) {
					c2[0][j] = rv(V[1]), c2[1][j] = rv(V[0]);
					mat += ev[V[1]][j] + od[V[0]][j];
				}
				else {
					c2[0][j] = rv(V[0]), c2[1][j] = rv(V[1]);
					mat += ev[V[0]][j] + od[V[1]][j];
				}
			}
			else {
				if(ev[V[2]][j] + od[V[3]][j] < ev[V[3]][j] + od[V[2]][j]) {
					c2[0][j] = rv(V[3]), c2[1][j] = rv(V[2]);
					mat += ev[V[3]][j] + od[V[2]][j];
				}
				else {
					c2[0][j] = rv(V[2]), c2[1][j] = rv(V[3]);
					mat += ev[V[2]][j] + od[V[3]][j];
				}
			}
		}

		if(mat > mx) {
			for(int i = 0; i < N; i++) {
				ans[i].clear();
				for(int j = 0; j < M; j++) {
					ans[i].push_back(c2[i % 2][j]);
				}
			}
			mx = mat;
		}

		next_permutation(V.begin(), V.end());
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			printf("%c", ans[i][j]);
		}
		puts("");
	}
	return 0;
}