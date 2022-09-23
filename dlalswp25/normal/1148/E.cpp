#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[303030];
int B[303030];
set<pii> S, T;
long long ss, st;
vector<pair<pii, int> > V;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]); ss += A[i];
	}
	for(int i = 1; i <= N; i++) {
		scanf("%d", &B[i]); st += B[i];
	}
	if(ss != st) { puts("NO"); return 0; }
	for(int i = 1; i <= N; i++) {
		S.insert({A[i], i});
		T.insert({B[i], i});
	}
	for(int i = 1; i <= N; i++) {
		auto it2 = T.end(); it2--;
		int now = it2 -> first;

		//for(auto i : S) printf("%d ", i.first); puts("");

		auto it1 = S.lower_bound({now, 0});
		if(it1 == S.end()) {
			puts("NO"); return 0;
		}
		if(i == N) {
			if(it1 -> first != now) { puts("NO"); return 0; }
			else break;
		}
		if(it1 -> first == now) {
			T.erase(it2);
			S.erase(it1);
			continue;
		}
		if(it1 == S.begin()) { puts("NO"); return 0; }

		auto it3 = it1; it3--;
		if(now - (it3 -> first) < (it1 -> first) - now) {
			int d = now - (it3 -> first);
			V.push_back({{it3 -> second, it1 -> second}, d});
			auto tmp = make_pair(it3 -> first + d, it3 -> second);
			S.insert({it3 -> first + d, it3 -> second});
			S.insert({it1 -> first - d, it1 -> second});
			S.erase(S.find(*it3));
			S.erase(S.find(*it1));
			S.erase(S.find(tmp));
		}
		else {
			int d = (it1 -> first) - now;
			V.push_back({{it3 -> second, it1 -> second}, d});
			S.insert({it3 -> first + d, it3 -> second});
			S.insert({it1 -> first - d, it1 -> second});
			auto tmp = make_pair(it1 -> first - d, it1 -> second);
			S.erase(S.find(*it3));
			S.erase(S.find(*it1));
			S.erase(S.find(tmp));
		}
		T.erase(it2);
	}
	puts("YES");
	printf("%d\n", V.size());
	for(auto i : V) {
		printf("%d %d %d\n", i.first.first, i.first.second, i.second);
	}
	return 0;
}