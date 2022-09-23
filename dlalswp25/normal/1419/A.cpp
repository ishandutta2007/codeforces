#include <bits/stdc++.h>

using namespace std;

int N;
char S[1010];
bool odd[2], even[2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", S + 1);

		odd[0] = odd[1] = even[0] = even[1] = false;
		for(int i = 1; i <= N; i++) {
			if(S[i] & 1) odd[i & 1] = true;
			else even[i & 1] = true;
		}

		if(N & 1) puts(odd[1] ? "1" : "2");
		else puts(even[0] ? "2" : "1");
	}
	return 0;
}