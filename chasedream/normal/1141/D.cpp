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

typedef pair <int, int> pr;
const int N = 400005;
queue <int> A[3005], B[3005];
char a[N], b[N];
int n, len;
pr ans[N];

void work() {
	For(i, 0, n) {
		if (a[i] == '?') A[0].push(i + 1);
		else A[a[i] - 'a' + 1].push(i + 1);
	}
	For(i, 0, n) {
		if (b[i] == '?') B[0].push(i + 1);
		else B[b[i] - 'a' + 1].push(i + 1);
	}
	rep(i, 1, 26) {
		int j = min(A[i].size(), B[i].size());
		For(k, 0, j) {
			ans[++len] = pr(A[i].front(), B[i].front());
			A[i].pop(); B[i].pop();
		}
	}
	
	rep(i, 1, 26) {
		int j = min(A[0].size(), B[i].size());
		For(k, 0, j) {
			ans[++len] = pr(A[0].front(), B[i].front());
			A[0].pop(); B[i].pop();
		}
	}
	
	rep(i, 1, 26) {
		int j = min(A[i].size(), B[0].size());
		For(k, 0, j) {
			ans[++len] = pr(A[i].front(), B[0].front());
			A[i].pop(); B[0].pop();
		}
	}
	
	int j = min(A[0].size(), B[0].size());
	For(k, 0, j) {
		ans[++len] = pr(A[0].front(), B[0].front());
		A[0].pop(); B[0].pop();
	}
}

int main() {
	scanf("%d%s%s", &n, a, b);
	work();
	printf("%d\n", len);
	rep(i, 1, len)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}