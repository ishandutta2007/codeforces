#include <bits/stdc++.h>

using namespace std;

int F[505050];
char S[505050];
char T[505050];
int N, M;
long long c[2];
string ans;

int main() {
	scanf("%s", S);
	N = strlen(S);
	for(int i = 0; i < N; i++) {
		c[S[i] - '0']++;
	}
	scanf("%s", T);
	M = strlen(T);

	int p = 0;
	for(int i = 1; i < M; i++) {
		while(p > 0 && T[i] != T[p]) p = F[p - 1];
		if(T[i] == T[p]) F[i] = ++p;
	}

	bool fg = false;
	while(1) {
		if(c[0] * c[1] == 0) break;
		if(!fg) {
			for(int i = 0; i < M; i++) {
				ans.push_back(T[i]);
				c[T[i] - '0']--;
				if(c[0] * c[1] == 0) break;
			}
			fg = true;
		}
		else {
			for(int i = F[M - 1]; i < M; i++) {
				ans.push_back(T[i]);
				c[T[i] - '0']--;
				if(c[0] * c[1] == 0) break;
			}
		}
		if(c[0] * c[1] == 0) break;
	}
	while(c[0]) { ans.push_back('0'); c[0]--; }
	while(c[1]) { ans.push_back('1'); c[1]--; }
	cout << ans << endl;
	return 0;
}