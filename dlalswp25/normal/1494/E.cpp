#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

map<pii, char> mp;
int x, y;

int main() {
	int N, M; scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		char c; scanf(" %c", &c);
		if(c == '+') {
			int a, b; char d; scanf("%d%d %c", &a, &b, &d);
			char t = mp[{b, a}];
			if(t == d) y++;
			else if(t) x++;
			mp[{a, b}] = d;
		}
		else if(c == '-') {
			int a, b; scanf("%d%d", &a, &b);
			char t = mp[{b, a}];
			char d = mp[{a, b}];
			if(t == d) y--;
			else if(t) x--;
			mp[{a, b}] = 0;
		}
		else {
			int k; scanf("%d", &k);
			if(k & 1) {
				puts(x + y ? "YES" : "NO");
			}
			else {
				puts(y ? "YES" : "NO");
			}
		}
	}

	return 0;
}