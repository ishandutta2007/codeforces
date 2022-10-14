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
int main()
{
    int n=read()*2;
    for(int i=1; i<=n; i++) a[i]=read();
    sort(a+1,a+n+1);
    if(a[1]==a[n]) puts("-1");
    else for(int i=1; i<=n; i++) printf("%d ",a[i]);
    return 0;
}