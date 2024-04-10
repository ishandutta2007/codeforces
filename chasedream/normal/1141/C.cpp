%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-fhoist-adjacent-loads")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;

#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define For(i, l, r) rep(i, l, r - 1)

void read(int &x) {
    x = 0; int f = 1;
    char op = getchar();
    while (!isdigit(op)) {
        if (op == '-') f = -1;
        op = getchar();
    }
    while (isdigit(op)) {
        x = 10 * x + op - '0';
        op = getchar();
    }
    x *= f;
}

const int N = 400005;
struct ele {
	int s, id;
	bool operator < (const ele b) const {
		return s < b.s;
	}
}qwq[N];
int a[N], ans[N], n;
int vis[N];

bool check() {
	int cha = 0;
	rep(i, 2, n) {
		if (ans[i] - ans[i - 1] != a[i])
			return 0;
	}
	return 1;
}

int main() {
	read(n);
	qwq[1].s = 0, qwq[1].id = 1;
	rep(i, 2, n) {
		read(a[i]);
		qwq[i].s = qwq[i - 1].s + a[i];
		qwq[i].id = i;
	}
	sort(qwq + 1, qwq + n + 1);
	for (int i = 1; i <= n; i++)
		ans[qwq[i].id] = i;
	
	if (check()) {
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	else puts("-1");
	return 0;
}