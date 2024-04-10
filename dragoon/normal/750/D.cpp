#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int n, t[40];
int board[301][301];

int dirr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirc[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct FW {
	int r, c, d;
	FW() {}
	FW(int _r, int _c, int _d) {
		r = _r;
		c = _c;
		d = _d;
	}
};
bool operator<(FW A, FW B) {
	if (A.r != B.r) return A.r < B.r;
	if (A.c != B.c) return A.c < B.c;
	return A.d < B.d;
}

void color(const FW& f, int t) {
	int  r = f.r, c = f.c;
	for (int i = 1; i <= t; i++) {
		board[r][c] = 1;
		r += dirr[f.d];
		c += dirc[f.d];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}

	set<FW> S;
	S.insert(FW(151, 151, 0));
	for (int i = 1; i <= n; i++) {
		set<FW> T;
		for (const FW& f : S) {
			color(f, t[i]);
			if (i == n) continue;
			FW a = f;
			a.r += dirr[f.d] * (t[i]- 1);
			a.c += dirc[f.d] * (t[i] - 1);
			FW b = a;
			a.d = (f.d + 1) % 8;
			a.r += dirr[a.d];
			a.c += dirc[a.d];
			b.d = (f.d + 7) % 8;
			b.r += dirr[b.d];
			b.c += dirc[b.d];
			T.insert(a);
			T.insert(b);
		}
		S = T;
	}

	int ans = 0;
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			ans += board[i][j];
		}

	}

	printf("%d\n", ans);

	return 0;
}