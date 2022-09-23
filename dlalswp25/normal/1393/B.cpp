#include <bits/stdc++.h>

using namespace std;

int cnt[101010];
set<int> S;
multiset<int> P;

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
		if(cnt[a] % 2 == 0) {
			P.insert(a);
			if(cnt[a] == 4) S.insert(a);
		}
	}

	int Q; scanf("%d", &Q);
	while(Q--) {
		char c; int x;
		scanf(" %c%d", &c, &x);
		if(c == '+') {
			cnt[x]++;
			if(cnt[x] % 2 == 0) {
				P.insert(x);
				if(cnt[x] == 4) S.insert(x);
			}
		}
		else {
			cnt[x]--;
			if(cnt[x] % 2) {
				P.erase(P.find(x));
				if(cnt[x] < 4) S.erase(x);
			}
		}
		if(S.size() && P.size() >= 4) puts("YES");
		else puts("NO");
	}

	return 0;
}