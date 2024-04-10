#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int ans,n,m,q[N],h[N];
char s[N],t[N];
int main(){
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	for(int i=1,j=1;j<=m;i++)
		if(s[i]==t[j])q[j++]=i;
	for(int i=n,j=m;j;i--)
		if(s[i]==t[j])h[j--]=i;
	for(int i=1;i<m;i++)ans=max(ans,h[i+1]-q[i]);
	printf("%d",ans);
}