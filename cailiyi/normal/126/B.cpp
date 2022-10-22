#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000100
using namespace std;
int n,nxt[N],maxn;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);nxt[0]=-1;
	for(int i=1;i<=n;i++)
	{
		nxt[i]=nxt[i-1];
		while(nxt[i]>=0 && s[nxt[i]+1]!=s[i]) nxt[i]=nxt[nxt[i]]; 
		++nxt[i];
		if(i<n) maxn=max(maxn,nxt[i]);
	}
	int x=nxt[n];
	while(x && x>maxn) x=nxt[x]; 
	if(!x) printf("Just a legend");
	else
	{
		for(int i=1;i<=x;i++) printf("%c",s[i]);
	}
	return 0;
}