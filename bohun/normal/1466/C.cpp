#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	
	
char s[100005];
int n;
	
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			bool bad = false;
			bad |= (i - 1 >= 1 && s[i - 1] == s[i]);
			bad |= (i - 2 >= 1 && s[i - 2] == s[i]);
			if (!bad) continue;
			res++;
			for (char c = 'a'; c <= 'z'; ++c) {
				bool ok = true;
				for (int j = 1; j <= 2; ++j) {
					if (i - j >= 1 && s[i - j] == c) ok = 0;
					if (i + j <= n && s[i + j] == c) ok = 0;
				}
				if (ok) {
					s[i] = c;
					break;
				}
			}
		}
		printf("%d\n", res);
	}
	
	return 0;
}