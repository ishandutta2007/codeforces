#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

int main() {
	string s; cin >> s;
	int a = 0, b = 0, n = 0;
	for(auto c: s)
		if(c == '(') a++;
		else if(c == ')') b++;
		else n++;

	string t = "";
	int k = 0;
	vector<int> ans;
	for(auto c: s)
		if(c == '#') {
			k++;
			if(k < n) {
				t += ')';
				ans.push_back(1);
			}
			else {
				int m = max(1, a - b - k + 1);
//				printf("%d %d %d\n", a, b, k);
				rep(i, m) t += ')';
				ans.push_back(m);
			}
		}
		else t += c;

	bool ok = true;
	int st = 0;
	for(auto c: t) {
		if(c == '(') st++;
		else if(--st < 0) {
			ok = false;
			break;
		}
	}
	if(st) ok = false;
	if(!ok) puts("-1");
	else
		for(auto v: ans) pi(v);


	return 0;
}