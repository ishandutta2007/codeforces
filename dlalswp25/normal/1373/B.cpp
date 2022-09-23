#include <bits/stdc++.h>

using namespace std;

vector<char> v;
char S[105];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		v.clear();
		scanf("%s", S);
		int N = strlen(S);
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			if(v.empty() || v.back() == S[i]) v.push_back(S[i]);
			else {
				cnt++;
				v.pop_back();
			}
		}
		puts(cnt & 1 ? "DA" : "NET");
	}
	return 0;
}