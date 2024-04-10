#include <bits/stdc++.h>

using namespace std;

int N;
char S[101010][5];
map<string, int> mp;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%s", S[i] + 1);
		}
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			int l = strlen(S[i] + 1);
			if(l == 1) ok = true;
			else if(l == 2) {
				if(S[i][1] == S[i][2]) ok = true;
			}
			else {
				if(S[i][1] == S[i][3]) ok = true;
			}
		}
		if(ok) { puts("YES"); continue; }

		mp.clear();
		for(int i = 1; i <= N; i++) {
			if(strlen(S[i] + 1) == 2) {
				string t;
				t.push_back(S[i][2]); t.push_back(S[i][1]);
				if(mp[t]) ok = true;
				mp[string(S[i] + 1)]++;
			}
			else {
				string t;
				t.push_back(S[i][3]); t.push_back(S[i][2]);
				if(mp[t]) ok = true;
			}
		}

		mp.clear();
		for(int i = N; i >= 1; i--) {
			if(strlen(S[i] + 1) == 2) {
				string t;
				t.push_back(S[i][2]); t.push_back(S[i][1]);
				if(mp[t]) ok = true;
				mp[string(S[i] + 1)]++;
			}
			else {
				string t;
				t.push_back(S[i][2]); t.push_back(S[i][1]);
				if(mp[t]) ok = true;
			}
		}

		mp.clear();
		for(int i = 1; i <= N; i++) {
			if(strlen(S[i] + 1) == 3) {
				string t(S[i] + 1); reverse(t.begin(), t.end());
				if(mp[t]) ok = true;
				mp[string(S[i] + 1)]++;
			}
		}

		puts(ok ? "YES" : "NO");
	}
	return 0;
}