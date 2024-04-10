#include <bits/stdc++.h>

using namespace std;

int N, Q;
char A[202020];
int S[202020];
int mnl[202020];
int mxl[202020];
int mnr[202020];
int mxr[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &Q);
		scanf("%s", A + 1);
		int t = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '+') t++;
			else t--;
			mnl[i] = min(mnl[i - 1], t);
			mxl[i] = max(mxl[i - 1], t);
			S[i] = t;
		}

		mnr[N + 1] = mxr[N + 1] = 0;
		for(int i = N; i >= 0; i--) {
			if(A[i] == '+') {
				mnr[i] = min(0, mnr[i + 1] + 1);
				mxr[i] = mxr[i + 1] + 1;
			}
			else {
				mnr[i] = mnr[i + 1] - 1;
				mxr[i] = max(0, mxr[i + 1] - 1);
			}
		}

		while(Q--) {
			int l, r; scanf("%d%d", &l, &r);
			int mx = max(mxl[l - 1], S[l - 1] + mxr[r + 1]);
			int mn = min(mnl[l - 1], S[l - 1] + mnr[r + 1]);
			printf("%d\n", mx - mn + 1);
		}
	}
	return 0;
}