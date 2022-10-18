#pragma warning(disable:4786)
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

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
//typedef __int64 LL;

map<int, int> M;
int n;
int a[100005];

int main()
{
	int i, ans;
	int now, at, run;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		M[a[i]]++;
	}

	int j;
	for(j = 0, i = 0; i < n; i++)
		if(!i || a[i-1]!=a[i])
			a[j++] = a[i];
	n = j;

	ans = a[0];
	run = 0;
	for(i = 0; i < n; i++)
	{
		at = a[i];
		now = run + M[a[i]];
		while( (now && i==n-1) || (now && at<a[i+1]) )
		{
			if(now&1);
			else ans++;

			now >>= 1;
			at++;
		}

		run = now;

		if(i<n-1)
		{
			ans += a[i+1] - at;
		}
	}

	printf("%d\n", ans);

	return 0;
}