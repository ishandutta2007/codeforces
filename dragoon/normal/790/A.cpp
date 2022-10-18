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
typedef long long int LL;
//typedef __int64 LL;

vector<string> VS;
char s[100][20];
int n, k;

int main()
{
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		for (char c = 'a'; c <= 'z'; c++) {
			string S;
			S.push_back(ch);
			S.push_back(c);
			VS.push_back(S);
		}
	}

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - k + 1; i++) {
		scanf("%s", s[i]);
	}
	int id = 0;
	vector<string> ans;
	ans.resize(n);
	for (int i = (n - k + 1); i < n; i++) {
		ans[i] = VS[id++];
	}
	for (int i = n - k + 1 - 1; i >= 0; i--) {
		if (s[i][0] == 'Y') {
			ans[i] = VS[id++];
		}
		else {
			ans[i] = ans[i + k - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%s", ans[i].c_str());
	}
	printf("\n");
	return 0;
}