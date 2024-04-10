#include <bits/stdc++.h>

using namespace std;

char S[105];
vector<int> v;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		int N = strlen(S + 1);
		v.clear();
		int c = 0;
		S[N + 1] = '0';
		for(int i = 1; i <= N + 1; i++) {
			if(S[i] == '0') {
				if(c) v.push_back(c);
				c = 0;
			}
			else c++;
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans = 0;
		for(int i = 0; i < v.size(); i += 2) ans += v[i];
		printf("%d\n", ans);
	}
	return 0;
}