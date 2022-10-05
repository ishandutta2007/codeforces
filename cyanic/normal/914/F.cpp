#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;
 
const int maxn = 100005;
bitset<maxn> p[26], now;
int n, Q, op, x, y, len;
char s[maxn], ch[maxn];
 
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep (i, 1, n) p[s[i]-'a'][i] = 1;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%s", &x, ch);
			p[s[x]-'a'][x] = 0;
			p[ch[0]-'a'][x] = 1;
			s[x] = ch[0];
		}
		else {
			scanf("%d%d%s", &x, &y, ch);
			len = strlen(ch); 
			if (y-x+1 < len) { puts("0"); continue; }
			now.set();
			rep (i, 0, len-1) now &= p[ch[i]-'a'] >> i;			
			printf("%d\n", int((now>>x).count()) - int((now>>(y-len+2)).count()));
		}
	}
	return 0;
}