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
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		sum=sum+t-1;
		if(sum%2==0) puts("2");
		else puts("1");
	}
	return 0;
}