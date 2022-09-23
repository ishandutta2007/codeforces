#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
char A[202020];
vector<pii> ans;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int s = 0, one = 0;
		for(int i = 1; i <= N; i++) {
			s ^= (A[i] - '0');
			one |= (A[i] - '0');
		}
		if(!one || s) { puts("NO"); continue; }
		ans.clear();
		vector<int> v;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '0') continue;
			int p = i;
			while(A[p % N + 1] == '0') {
				ans.emplace_back(p, p % N + 1);
				p = p % N + 1;
			}
			v.push_back(p);
		}
		for(int i = 1; i < v.size(); i++) ans.emplace_back(v[0], v[i]);
		puts("YES");
		for(pii i : ans) printf("%d %d\n", i.first, i.second);
	}
	return 0;
}