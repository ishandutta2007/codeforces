// betaveros
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
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

bool blocks[1000008];
bool ans[1000008];
const int N = 1000001;
int n;
void readInput() {
	scanf("%d", &n);
	fill(blocks, blocks + N + 2, false);
	repeat(n) {
		int x;
		scanf("%d", &x);
		blocks[x] = true;
	}
}

vector<int> misses;
int nMisses = 0;
void tc() {
	readInput();
	printf("%d\n", n);
	fill(ans, ans + N + 2, false);
	fori (i, 1, 500001) {
		if (blocks[i] && !blocks[N-i]) {
			ans[N-i] = true;
		} else if (!blocks[i] && blocks[N-i]) {
			ans[i] = true;
		} else if (blocks[i] && blocks[N-i]) {
			nMisses++;
		} else if (!blocks[i] && !blocks[N-i]) {
			misses.push_back(i);
		} else throw 123948;
	}
	repeat (nMisses) {
		int i = misses.back();
		ans[i] = true;
		ans[N-i] = true;
		misses.pop_back();
	}
	bool first = true;
	fori (i, 1, N) {
		if (ans[i]) {
			if (first) first = false;
			else printf(" ");
			printf("%d", i);
		}
	}
	printf("\n");
}

int main() { tc(); }