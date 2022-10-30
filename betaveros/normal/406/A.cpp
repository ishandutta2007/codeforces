// betaveros
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define debug(code) code

int n;
int trace = 0;

void tc() {
	scanf("%d", &n);
	fori (i, 0, n) {
		fori (j, 0, n) {
			int x;
			scanf("%d", &x);
			if (i == j) trace ^= x;
		}
	}
	int ops;
	scanf("%d", &ops);
	repeat(ops) {
		int op;
		scanf("%d", &op);
		if (op == 1 || op == 2) { int _; scanf("%d", &_); trace ^= 1; }
		else if (op == 3) printf("%d", trace);
	}
	printf("\n");
}

int main() { tc(); }