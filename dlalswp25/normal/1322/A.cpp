#include <bits/stdc++.h>

using namespace std;

char A[1010101];
int N;

int main() {
	int ans = 0, s = 0;

	scanf("%d", &N);
	scanf("%s", A + 1);
	for(int i = 1; i <= N; i++) {
		int tmp = s;
		if(A[i] == '(') s++;
		else s--;
		if(s < 0) ans++;
		else if(tmp < 0) ans++;
	}

	if(s != 0) puts("-1");
	else printf("%d\n", ans);

	return 0;
}