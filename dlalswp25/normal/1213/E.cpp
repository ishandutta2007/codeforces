#include <bits/stdc++.h>

using namespace std;

char s[3];
char t[3];

int N;

bool chk(string p) {
	if(s[0] == p[0] && s[1] == p[1]) return true;
	if(t[0] == p[0] && t[1] == p[1]) return true;
	return false;
}

void f(string p) {
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= N; j++) printf("%c", p[i]);
	}
	puts("");
}

int main() {
	scanf("%d", &N);
	scanf("%s", s);
	scanf("%s", t);

	puts("YES");
	if(!chk("ab") && !chk("bc") && !chk("ca")) {
		for(int i = 1; i <= N; i++) printf("abc"); puts("");
		return 0;
	}
	if(!chk("ba") && !chk("cb") && !chk("ac")) {
		for(int i = 1; i <= N; i++) printf("acb"); puts("");
		return 0;
	}

	if(!chk("ab") && !chk("bc")) { f("abc"); return 0; }
	if(!chk("ac") && !chk("cb")) { f("acb"); return 0; }
	if(!chk("ba") && !chk("ac")) { f("bac"); return 0; }
	if(!chk("bc") && !chk("ca")) { f("bca"); return 0; }
	if(!chk("ca") && !chk("ab")) { f("cab"); return 0; }
	if(!chk("cb") && !chk("ba")) { f("cba"); return 0; }

	return 0;
}