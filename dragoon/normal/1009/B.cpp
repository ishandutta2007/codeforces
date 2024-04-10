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
#include<unordered_set>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

char S[100005];

int main() {
#ifdef LOCAL
	//freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	scanf("%s", S);

	int j = -1;
	for (int i = 0; i < S[i]; i++) {
		if (S[i] == '2') {
			j = i;
			break;
		}
	}

	int len = strlen(S);
	if (j == -1) {
		sort(S, S + len);
		printf("%s\n", S);
		return 0;
	}

	string T = "";
	sort(S, S + j);
	for (int i = 0; i < j; i++) T.push_back(S[i]);
	int cnt = 0;
	string F = "";
	for (int i = j; i < len; i++) {
		if (S[i] == '1') {
			cnt++;
		}
		else {
			F.push_back(S[i]);
		}
	}
	for (int i = 0; i < cnt; i++) T.push_back('1');
	T = T + F;
	printf("%s\n", T.c_str());
	return 0;
}