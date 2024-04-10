#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

int last[26],l,r;
char ans[2][13];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s; cin >> s;
	F0R(i,26) last[i] = -1;
	F0R(i,s.length()) {
	    if (last[int(s[i]-'A')] != -1) {
	        l = last[s[i]-'A'], r = i;
	        break;
	    } else last[s[i]-'A'] = i;
	}
	int d = r-l;
	if (d == 1) {
	    cout << "Impossible";
	    return 0;
	} else if (d % 2 == 1) {
	    ans[0][12-d/2] = s[l];
	    FOR(i,13-d/2,13) ans[0][i] = s[i-13+d/2+l+1];
	    FOR(i,13-d/2,13) ans[1][i] = s[13-d/2-i+r-1];
	    ans[1][12-d/2] = s[l-1];
	    int a = 12-d/2, b = l-1;
	    while (a>0 && b>0) ans[1][--a] = s[--b];
	    while (b>0) ans[0][a++] = s[--b];
	    a = 12-d/2, b = r;
	    while (a>0 && b<26) ans[0][--a] = s[++b];
	    while (b<26) ans[1][a++] = s[++b];
	} else {
	    ans[0][13-d/2] = s[l];
	    FOR(i,14-d/2,13) ans[0][i] = s[i-14+d/2+l+1];
	    FOR(i,13-d/2,13) ans[1][i] = s[13-d/2-i+r-1];
	    int a = 13-d/2, b = l;
	    while (a>0 && b>0) ans[1][--a] = s[--b];
	    while (b>0) ans[0][a++] = s[--b];
	    a = 13-d/2, b = r;
	    while (a>0 && b<26) ans[0][--a] = s[++b];
	    while (b<26) ans[1][a++] = s[++b];
	}
	F0R(i,13) cout << ans[0][i];
	cout << "\n";
	F0R(i,13) cout << ans[1][i];
}