#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
using point = pair<int, int>;
const int maxn = 5555;
char s[maxn];
inline point go(point A, char c) {
	auto x = A.first, y = A.second;
	if (c == 'L')
		return { x - 1, y };
	else if (c == 'R')
		return { x + 1, y };
	else if (c == 'U')
		return { x, y + 1 };
	else // D
		return { x, y - 1 };
}
int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		set<point> P;
		point S{ 0, 0 };
		for (int i = 0; i < n; ++i) {
			S = go(S, s[i]);
			P.insert(S);
		}
		if (P.count({ 0, 0 }))
			P.erase(point{ 0, 0 });
		point answer(0, 0);
		for (auto ob : P) {
			point S{ 0, 0 };
			for (int i = 0; i < n; ++i) {
				auto T = go(S, s[i]);
				if (T != ob)
					S = T;
			}
			if (S == make_pair(0, 0)) {
				answer = ob;
				break;
			}
		}
		printf("%d %d\n", answer.first, answer.second);
	}
	return 0;
}