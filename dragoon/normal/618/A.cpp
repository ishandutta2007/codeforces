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

int main()
{
	stack<int> S;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int now = 1;
		while (!S.empty()) {
			if (S.top() == now) {
				int p = S.top();
				S.pop();
				now++;
			}
			else {
				break;
			}
		}
		S.push(now);
	}
	vector<int> V;
	while (!S.empty()) {
		int s = S.top();
		S.pop();
		V.push_back(s);
	}
	for (int i = V.size() - 1; i >= 0; i--) {
		if (i != V.size() - 1) printf(" ");
		printf("%d", V[i]);
	}
	printf("\n");
	return 0;
}