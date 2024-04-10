#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, Q;
set<int> S;
multiset<int> D;

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		S.insert(a);
	}
	auto it = S.begin(); auto bef = it; it++;
	while(it != S.end()) {
		D.insert(*it - *bef);
		bef = it; it++;
	}

	D.insert(0);

	int mn = *S.begin(), mx = *S.rbegin();
	printf("%d\n", mx - mn - *D.rbegin());

	while(Q--) {
		int t, x; scanf("%d%d", &t, &x);
		// printf("S "); for(int i : S) printf("%d ", i); puts("");
		// printf("D "); for(int i : D) printf("%d ", i); puts("");
		if(t == 0) {
			if(S.size() == 1) {
				S.clear(); D.clear();
				D.insert(0);
				mn = INF; mx = 0;
				puts("0");
				continue;
			}

			auto it = S.find(x);
			int ld = -1, rd = -1;
			if(it != S.begin()) {
				auto tmp = it; tmp--;
				ld = *it - *tmp;
				D.erase(D.find(ld));
			}

			if(it != --S.end()) {
				auto tmp = it; tmp++;
				rd = *tmp - *it;
				D.erase(D.find(rd));
			}

			S.erase(it);

			if(ld != -1 && rd != -1) D.insert(ld + rd);	
			else if(ld == -1) mn = *S.begin();
			else mx = *S.rbegin();
			printf("%d\n", mx - mn - *D.rbegin());
		}
		else {
			if(!S.size()) {
				S.insert(x);
				mn = mx = x;
				puts("0");
				continue;
			}

			S.insert(x);
			auto it = S.find(x);
			int ld = -1, rd = -1;
			if(it != S.begin()) {
				auto tmp = it; tmp--;
				ld = *it - *tmp;
				D.insert(ld);
			}
			if(it != --S.end()) {
				auto tmp = it; tmp++;
				rd = *tmp - *it;
				D.insert(rd);
			}
			if(ld != -1 && rd != -1) D.erase(D.find(ld + rd));
			else if(ld == -1) mn = *S.begin();
			else mx = *S.rbegin();
			printf("%d\n", mx - mn - *D.rbegin());
		}
	}

	return 0;
}