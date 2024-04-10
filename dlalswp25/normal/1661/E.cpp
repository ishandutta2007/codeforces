#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, Q;
char A[3][505050];
int V[505050];
int EH[505050];
int EV[505050];
int F[505050];
vector<pii> F2;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < 3; i++) scanf("%s", A[i] + 1);
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= N; j++) {
			V[j] += (A[i][j] == '1');
		}
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 1; j <= N; j++) {
			EV[j] += (A[i][j] == '1' && A[i + 1][j] == '1');
		}
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j < N; j++) {
			EH[j] += (A[i][j] == '1' && A[i][j + 1] == '1');
		}
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 1; j < N; j++) {
			F[j] += (A[i][j] == '1' && A[i][j + 1] == '1' && A[i + 1][j] == '1' && A[i + 1][j + 1] == '1');
		}
	}

	int l = -1;
	for(int i = 1; i <= N; i++) {
		if(A[0][i] != '1' || A[2][i] != '1') { l = -1; continue; }
		if(A[1][i] == '1') {
			if(l != -1 && i - l > 1) F2.emplace_back(l, i);
			l = i;
		}
	}

	for(int i = 1; i <= N; i++) {
		V[i] += V[i - 1];
		EH[i] += EH[i - 1];
		EV[i] += EV[i - 1];
		F[i] += F[i - 1];
	}

	scanf("%d", &Q);
	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		int v = V[r] - V[l - 1];
		int e = (EV[r] - EV[l - 1]) + (EH[r - 1] - EH[l - 1]);
		int f = F[r - 1] - F[l - 1];
		auto itl = lower_bound(F2.begin(), F2.end(), pii(l, 0));
		auto itr = lower_bound(F2.begin(), F2.end(), pii(r, 0));
		if(itl != itr) {
			itr--;
			if(itr->second > r) itr--;
			f += (itr - itl) + 1;
		}
		printf("%d\n", v - e + f);
	}
	return 0;
}