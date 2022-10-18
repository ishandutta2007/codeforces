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

char word[100][100];

inline int find(set<char> &S, char ch) {
	return S.find(ch) != S.end();
}
int main()
{
	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", word[i]);
	}

	int ans = 0;
	for (int i = 0; i < R - 1; i++) {
		for (int j = 0; j < C - 1; j++) {
			set<char> S;
			S.insert(word[i][j]);
			S.insert(word[i][j + 1]);
			S.insert(word[i + 1][j + 1]);
			S.insert(word[i + 1][j]);
			ans += find(S, 'f') && find(S, 'a') && find(S, 'c') && find(S, 'e');
		}
	}
	printf("%d\n", ans);
	return 0;
}