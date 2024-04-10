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

int tree[6000000][2];
int root = 1;
int cnt[6000000];
int cur = 1;
void update(int x, int val) {
	int now = root;
	cnt[now] += val ;
	for (int i = 29; i >= 0; i--) {
		int c = (x >> i) & 1;
		if (tree[now][c] == 0) {
			cur++;
			tree[now][c] = cur;
		}
		now = tree[now][c];
		cnt[now] += val;
	}
}

void query(int x) {
	int now = root;
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		int c = (x >> i) & 1;
		if (tree[now][1 ^ c] == 0 || cnt[tree[now][1^c]] == 0) {
			ans = ans;
		}
		else {
			ans ^= (1 << i);
			c ^= 1;
		}
		now = tree[now][c];
	}
	printf("%d\n", ans);
}

int main()
{
	int q, x;
	char word[10];

	update(0, 1);

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%s %d", word, &x);
		if (word[0] == '+') update(x, 1);
		else if (word[0] == '-') update(x, -1);
		else query(x);
	}

	return 0;
}