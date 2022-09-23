#include <bits/stdc++.h>

using namespace std;

int N;
char A[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int zero = 0;
		for(int i = 1; i <= N; i++) zero += A[i] == '0';
		vector<int> v;
		for(int i = 1; i <= zero; i++) if(A[i] == '1') v.push_back(i);
		for(int i = zero + 1; i <= N; i++) if(A[i] == '0') v.push_back(i);
		if(!v.size()) { puts("0"); continue; }
		puts("1");
		printf("%d ", v.size());
		for(int i : v) printf("%d ", i); puts("");
	}
	return 0;
}