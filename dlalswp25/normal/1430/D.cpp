#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
char A[202020];

vector<int> v;
set<pii> s2;
set<int> s1;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear(); s1.clear(); s2.clear();
		scanf("%d", &N);
		scanf("%s", A + 1);
		int l = 1;
		for(int i = 1; i <= N; i++) {
			if(A[i] != A[l]) {
				v.push_back(i - l);
				l = i;
			}
		}
		v.push_back(N - l + 1);
		int M = v.size();

		for(int i = 0; i < M; i++) {
			if(v[i] == 1) s1.insert(i);
			else s2.insert(pii(i, v[i]));
		}

		int ans = 0;
		for(int i = 0; i < M; i++) {
			if(s1.find(i) == s1.end()) {
				s2.erase(s2.begin());
				ans++;
			}
			else if(s1.size() == M - i) { ans += (M - i + 1) / 2; break; }
			else {
				auto it = s2.begin();
				if(it -> second == 2) {
					s1.insert(it -> first);
					s2.erase(it);
				}
				else {
					auto tmp = *it; tmp.second--;
					s2.erase(it);
					s2.insert(tmp);
				}
				ans++;
				s1.erase(s1.begin());
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}