#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char S[1010101];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		scanf("%s", S + 1);
		K = strlen(S + 1);
		int xs = 0, ys = 0;
		int mnX = 0, mnY = 0, mxX = 0, mxY = 0;
		int ansX = -1, ansY = -1;

		for(int i = 1; i <= K; i++) {
			if(S[i] == 'D') xs++;
			else if(S[i] == 'U') xs--;
			else if(S[i] == 'R') ys++;
			else ys--;
			mnX = min(mnX, xs);
			mxX = max(mxX, xs);
			mnY = min(mnY, ys);
			mxY = max(mxY, ys);
			if(-mnX + mxX + 1 > N) {
				if(S[i] == 'U') ansX = -mnX;
				else ansX = -mnX + 1;
				break;
			}
			if(-mnY + mxY + 1 > M) {
				if(S[i] == 'L') ansY = -mnY;
				else ansY = -mnY + 1;
				break;
			}
		}
		if(ansX < 0) ansX = -mnX + 1;
		if(ansY < 0) ansY = -mnY + 1;
		printf("%d %d\n", ansX, ansY);
	}
	return 0;
}