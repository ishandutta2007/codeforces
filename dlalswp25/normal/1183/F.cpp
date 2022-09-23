#include <bits/stdc++.h>

using namespace std;

int Q, N;
set<int> S;
vector<int> v;

int main() {
	scanf("%d", &Q);
	while(Q--) {
		S.clear();

		scanf("%d", &N);

		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x); S.insert(x);
		}

		int ans = 0;
		auto it = S.end(); it--;

		int t = (*it);
		if(S.find(t / 2) != S.end() && S.find(t / 3) != S.end() && S.find(t / 5) != S.end()) {
			ans = t / 2 + t / 3 + t / 5;
		}

		int sum = t;

		for(int z = 0; z < 2; z++) {
			for(int i : S) if(t % i == 0) v.push_back(i);
			while(v.size()) { S.erase(v.back()); v.pop_back(); }

			if(!S.size()) break;

			auto it = S.end(); it--;
			t = (*it);
			sum += t;
		}
		printf("%d\n", max(sum, ans));
	}
	return 0;
}