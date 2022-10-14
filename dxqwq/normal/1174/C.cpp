#include<bits/stdc++.h>
using namespace std;
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int ans[1000003];
int main()
{
    int n=read(),now=0;
    for(int i=2; i<=n; i++) if(!ans[i]) { ++now; for(int j=1; i*j<=n; j++) ans[i*j]=now;}
    for(int i=2; i<=n; i++) printf("%d ",ans[i]);
    return 0;
}