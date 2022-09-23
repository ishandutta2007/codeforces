#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int cnt[101010];
int acnt[101010];
set<pii> S;

int main() {
	int N; scanf("%d", &N);
	int ans = 1;

	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		if(acnt[cnt[x]] > 0) S.erase(S.find({cnt[x], acnt[cnt[x]]}));
		if(acnt[cnt[x]] > 1) S.insert({cnt[x], acnt[cnt[x]] - 1});
		acnt[cnt[x]]--;
		cnt[x]++;
		acnt[cnt[x]]++;
		if(acnt[cnt[x]] > 1) S.erase(S.find({cnt[x], acnt[cnt[x]] - 1}));
		if(acnt[cnt[x]] > 0) S.insert({cnt[x], acnt[cnt[x]]});

		if(S.size() > 2) continue;
		auto tmp = S.begin();
		int a = tmp -> first; tmp++;
		if(S.size() == 1) {
			if(a == 1 || acnt[a] == 1) ans = max(ans, i);
		}
		else {
			int b = tmp -> first;
			if(a == 1 && acnt[a] == 1) ans = max(ans, i);
			else if(acnt[b] == 1 && a == b - 1) ans = max(ans, i);
		}
	}
	printf("%d\n", ans);
	return 0;
}