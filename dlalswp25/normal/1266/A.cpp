#include <bits/stdc++.h>

using namespace std;

char S[505];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", S + 1);
		int N = strlen(S + 1);
		int sum = 0;
		bool zero = false;
		int even = 0;
		for(int i = 1; i <= N; i++) {
			if(S[i] == '0') zero = true;
			sum += (S[i] - '0');
			if((S[i] - '0') % 2 == 0) even++;
		}
		if(sum % 3 == 0 && zero && even > 1) puts("red");
		else puts("cyan");
	}

	return 0;
}