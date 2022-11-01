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
/*
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
*/
int main(void) {
	
	int n,q;
	int a[300005]={0},b[300005]={0},c[300005]={0},d[300005]={0},ans=0,tmax=1;	
	int j=1;
	scanf("%d %d",&n,&q);	
	while(q--)
	{
		int l,k;		
		scanf("%d %d",&l,&k);				
		if(l==1)
		{
			a[j]=k;
			b[k]++;
			ans++;
		    j++;
		}		
		if(l==2)
		{
			ans-=(b[k]-c[k]);
			c[k]=b[k];
		}		
		if(l==3)
		{
			while(tmax<=k)
			{
				d[a[tmax]]++;
				if(d[a[tmax]]>c[a[tmax]])
				{
					c[a[tmax]]++;
					ans--;
				}
				tmax++;
			}
		}		
		printf("%d\n",ans);
	}
	return 0;	
}