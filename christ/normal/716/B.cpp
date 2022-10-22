#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 2e5+4, MAXV = 1e4+5;
int diff = 0, idk = 0;
int cnt[26];
char s[MN];
void add (char c) {
	if (c == '?') idk++;
	else {
		if (!(cnt[c-'A']++)) ++diff;
	}
}
void del (char c) {
	if (c == '?') --idk;
	else {
		if (!(--cnt[c-'A'])) --diff;
	}
}
int n;
void solve (int st) {
	vector<char> dont;
	for (int i = 0; i < 26; i++) if (!cnt[i]) dont.push_back(i+'A');
	for (int i = st; i < st + 26; i++) {
		if (s[i] == '?') {
			s[i] = dont.back();
			dont.pop_back();
		}
	}
	for (int i = 0; i < st; i++) if (s[i] == '?') s[i] = 'A';
	for (int i = st+26; i < n; i++) if (s[i] == '?') s[i] = 'A';
	printf ("%s\n",s);
	exit(0);
}
int main () { 
	scanf ("%s",s);
	n = strlen(s);
	if (n < 26) return !printf ("-1\n");
	for (int i = 0; i < 26; i++) add(s[i]);
	if (diff + idk == 26) {
		solve(0);
	}
	for (int i = 1; i <= n - 26; i++) {
		del(s[i-1]);
		add(s[i+25]);
		if (diff + idk == 26) solve(i);
	}
	printf ("-1\n");
	return 0;
}