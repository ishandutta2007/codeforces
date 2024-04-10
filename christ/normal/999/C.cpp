#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
bool bad[MN];
deque<int> pos[26];
char s[MN];
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	scanf ("%s",s+1);
	for (int i = 1; i <= n; i++) {
		pos[s[i]-'a'].push_back(i);
	}
	while (k--) {
		for (int i = 0; i < 26; i++) {
			if (!pos[i].empty()) {
				bad[pos[i].front()] = 1;
				pos[i].pop_front();
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) if (!bad[i]) putchar(s[i]);
	putchar(10);
    return 0;
}