#include<bits/stdc++.h>
using namespace std;
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int a[1000003];
bool vis[1000003];
int main() 
{
	int n=1<<read(),x=read(),len=0;
	vis[0]=vis[x]=1;
	for(int i=1; i<n; i++) if(!vis[i]) vis[i^x]=true,a[++len]=i;
	printf("%d\n",len);
	for(int i=1; i<=len; i++) printf("%d ",a[i-1]^a[i]);
	return 0;
}