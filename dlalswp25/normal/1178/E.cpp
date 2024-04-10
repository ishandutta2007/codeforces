#include <bits/stdc++.h>

using namespace std;

char S[1010101];
int N;
vector<char> ans1;
vector<char> ans2;

int cnt[150];

int main() {
	scanf("%s", S);
	int N = strlen(S);

	int l = 0, r = N - 1;

	for(int i = 0; l < r; i++) {
		cnt['a'] = cnt['b'] = cnt['c'] = 0;
		cnt[S[l]]++;
		cnt[S[l + 1]]++;
		cnt[S[r]]++;
		cnt[S[r - 1]]++;

		char c;
		if(cnt['a'] >= 2) c = 'a';
		else if(cnt['b'] >= 2) c = 'b';
		else c = 'c';

		if(r - l + 1 >= 4) ans2.push_back(c);
		ans1.push_back(c);

		l += 2;
		r -= 2;
	}
	reverse(ans2.begin(), ans2.end());
	for(char i : ans1) printf("%c", i);
	for(char i : ans2) printf("%c", i);
	puts("");
	return 0;
}