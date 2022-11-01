//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read()
{
	int v = 0, f = 0;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(n==1){
			if(i%2==1) printf("I hate ");
			if(i%2==0)printf("I love ");
		}
		if(n>1)
		{
			if(i%2==1) printf("I hate ");
		    if(i%2==0)printf("I love ");
		    if(i<n)
		    printf("that ");
		}
		
	}
	puts("it");
	return 0;
}