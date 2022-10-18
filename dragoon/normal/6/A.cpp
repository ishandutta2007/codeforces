#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <math.h>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <utility>
#include<stack>
using namespace std;

typedef pair<int,int> PII;

//typedef __int64 LL;
//typedef long long LL;

#define MAX(A,B) ((A) > (B) ? (A) : (B))
#define MIN(A,B) ((A) < (B) ? (A) : (B))
#define ABS(X) ((X) > 0 ? (X) : (-(X)))
#define S(X) ((X)*(X))

int main()
{
	int a[5],tri,seg,i,j,k;

	tri=0;
	seg=0;
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	for(i=0;i<4;i++)
		for(j=i+1;j<4;j++)
			for(k=j+1;k<4;k++)
			{
				if(a[i]+a[j]>a[k] && a[k]+a[j]>a[i] && a[i]+a[k]>a[j])
					tri=1;
				if(a[i]+a[j]==a[k] || a[k]+a[j]==a[i] || a[i]+a[k]==a[j])
					seg=1;
			}

	if(tri)
		printf("TRIANGLE\n");
	else if(seg)
		printf("SEGMENT\n");
	else
		printf("IMPOSSIBLE\n");

	return 0;
}