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

void Print(vector<int> V)
{
	int i;

	printf("%d", V.size());
	for(i = 0; i < V.size(); i++)
		printf(" %d", V[i]);
	printf("\n");
}

int main()
{
	vector<int> V1, V2, V3;
	int i, a, n; 

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a);

		if(a < 0 && V1.size()==0) V1.push_back(a);
		else if(a > 0 && V2.size()==0) V2.push_back(a);
		else V3.push_back(a);
	}

	if(V2.size()==0)
	{
		sort(V3.begin(), V3.end(), greater<int>());
		int sz = V3.size();
		V2.push_back(V3[sz-2]);
		V2.push_back(V3[sz-1]);
		V3.pop_back();
		V3.pop_back();
	}

	Print(V1);
	Print(V2);
	Print(V3);

	return 0;
}