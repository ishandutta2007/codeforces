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

char A[100002],B[200],C[200];
int fail1[200],fail2[200];

int check()
{
	int len,now,L,i;

	len=strlen(A);
	now=-1;

	L = strlen(B);

	for(i=0;i<len;i++)
	{
		while(now!=-1 && A[i]!=B[now+1])
			now = fail1[now];

		if(A[i]==B[now+1])
		{
			now++;

			if(now==L-1)
				break;
		}
	}


	len=strlen(A);
	L = strlen(C);
	now=-1;

	for(i=i+1;i<len;i++)
	{
		while(now!=-1 && A[i]!=C[now+1])
			now = fail2[now];

		if(A[i]==C[now+1])
		{
			now++;

			if(now==L-1)
				return 1;
		}
	}

	return 0;
}

void f()
{
	int len,now,i;

	fail1[0]=-1;
	len=strlen(B);
	now=-1;
	for(i=1;i<len;i++)
	{
		while(now!=-1 && B[i]!=B[now+1])
			now = fail1[now];

		if(B[i]==B[now+1])
		{
			fail1[i]=++now;
		}
		else
			now=fail1[i]=-1;
	}


	fail2[0]=-1;
	len=strlen(C);
	now=-1;
	for(i=1;i<len;i++)
	{
		while(now!=-1 && C[i]!=C[now+1])
			now = fail2[now];

		if(B[i]==B[now+1])
		{
			fail2[i]=++now;
		}
		else
			now=fail2[i]=-1;
	}
}


int main()
{
	int a,b,i,j,len;

	scanf("%s%s%s",A,B,C);

	f();

	a=check();
	len=strlen(A);
	for(i=0,j=len-1;i<j;i++,j--)
		swap(A[i],A[j]);

	b=check();

	if(a && b) printf("both\n");
	else if(a) printf("forward\n");
	else if(b) printf("backward\n");
	else printf("fantasy\n");

	return 0;
}