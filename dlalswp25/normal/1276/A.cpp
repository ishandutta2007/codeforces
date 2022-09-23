#include <bits/stdc++.h>

using namespace std;

char S[1010101];
vector<int> ans;

bool one(int i) {
	return S[i] == 'o' && S[i + 1] == 'n' && S[i + 2] == 'e';
}
bool two(int i) {
	return S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o';
}
bool twone(int i) {
	return S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o' && S[i + 3] == 'n' && S[i + 4] == 'e';
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ans.clear();
		scanf("%s", S + 1);
		int N = strlen(S + 1);
		int i = 1;
		while(i <= N) {
			if(twone(i)) {
				ans.push_back(i + 2);
				i += 5;
				continue;
			}
			if(two(i)) {
				ans.push_back(i + 1);
				i += 3;
				continue;
			}
			if(one(i)) {
				ans.push_back(i + 1);
				i += 3;
				continue;
			}
			i++;
		}
		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}