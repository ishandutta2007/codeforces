#include <iostream>
#include <cstring>
using namespace std;
char s[10010], t[10010];
int main() {
	scanf("%s", s);
	int T; scanf("%d", &T);
	while(T--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		k %= r - l + 1;
		if(k == 0) continue;
		l--, r--;
		memcpy(t + l, s + l, r - l + 1);
		int j = l;
		for(int i = r - k + 1; i <= r; ++i)
			s[j++] = t[i];
		for(int i = l; j <= r; ++i)
			s[j++] = t[i];
	}
	puts(s);

	return 0;
}