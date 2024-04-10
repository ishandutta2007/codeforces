#include <bits/stdc++.h>

using namespace std;

bool chk[500005];
int main() {
	int q;
	scanf("%d", &q);
	int c = 0;
	priority_queue<pair<int, int>> Q;
	set<pair<int, int>> S;
	while (q--) {
		int o, x;
		scanf("%d", &o);
		if (o == 1) {
			scanf("%d", &x);
			c++;
			Q.push({ x,-c });
			S.insert({ c,x });
		}
		else if (o == 2) {
			auto P = *S.begin();
			chk[P.first] = 1;
			printf("%d ", P.first);
			S.erase(S.begin());
		}
		else {
			while (chk[-Q.top().second])Q.pop();
			auto P = Q.top();
			Q.pop();
			P.second = -P.second;
			S.erase({ P.second,P.first });
			chk[P.second] = 1;
			printf("%d ", P.second);
		}
	}
}