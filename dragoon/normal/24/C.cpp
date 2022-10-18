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
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X) < 0 ? (-(X)) : (X))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;
typedef __int64 LL;

LL Mx, My;
int Ax[100002],Ay[100002];
int s,i;
LL t;

int main()
{
	int n;
	LL j;
	cin>>n>>j;

	cin>>Mx>>My;
	for(i=0;i<n;i++) scanf("%d%d",&Ax[i],&Ay[i]);

	s=1;
	if(j&1) Mx=-Mx, My=-My, s=-1;

	for(i=0;i<n;i++)
	{
		t=(j-i+n-1)/n;
		
		s*=-1;
		if(t&1)
		{
			Mx = (Mx + s*2*Ax[i]);
			My = (My + s*2*Ay[i]);
		}
		else
		{
			continue;
		}
	}

	cout<<Mx;
	printf(" ");
	cout<<My<<endl;

	return 0;
}