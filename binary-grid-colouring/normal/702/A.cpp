#include<bits/stdc++.h>
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
#define MP(x,y) make_pair(x,y)  
template <class T1, class T2>inline void getmax(T1 &a, T2 b) { if (b>a)a = b; }  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) { if (b<a)a = b; }
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
	int n; int a,b=0,c=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a>b)c++;
		else c=1;
		b=a;
		ans=max(ans,c);
	}
	cout<<ans<<endl;
	return 0;
}