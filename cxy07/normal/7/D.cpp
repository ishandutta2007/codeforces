#include<bits/stdc++.h>
using namespace std;

const int MAXLEN = 5e6 + 10;
const int base = 131;

#define ull unsigned long long

int n,ans;
int val[MAXLEN];
char s[MAXLEN];
ull hash1[MAXLEN],rev[MAXLEN],p[MAXLEN];

inline ull gethash(int l,int r) {return hash1[r] - hash1[l - 1] * p[r - l + 1];}
inline ull getrev(int l,int r) {return rev[l] - rev[r + 1] * p[r - l + 1];}

int main () {
    ios::sync_with_stdio(0);
	cin >> s + 1;
	n = strlen(s + 1);
	p[0] = 1;
	for(register int i = 1;i <= n; ++i)
		p[i] = p[i - 1] * base;
	for(register int i = 1;i <= n; ++i)
		hash1[i] = hash1[i - 1] * base + (s[i] - 'a' + 1);
	for(register int i = n;i >= 1; --i)
		rev[i] = rev[i + 1] * base + (s[i] - 'a' + 1);
	val[1] = 1; ans = 1;
	for(register int i = 2;i <= n; ++i) {
		if(gethash(1,i) == getrev(1,i)) 
			val[i] = val[i / 2] + 1;
		ans += val[i];
	}
	cout << ans << endl;
	return 0;
}