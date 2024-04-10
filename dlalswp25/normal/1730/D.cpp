#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];
char B[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		map<string, int> mp;
		for(int i = 1; i <= N; i++) {
			string s = {A[i], B[N - i + 1]};
			if(s[0] > s[1]) swap(s[0], s[1]);
			if(mp.find(s) != mp.end()) mp.erase(s);
			else mp[s]++;
		}
		if(mp.size() >= 2) puts("NO");
		else if(mp.size() == 1) {
			string s = mp.begin()->first;
			if(s[0] == s[1]) puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}
	return 0;
}