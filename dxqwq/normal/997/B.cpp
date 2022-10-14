#include<bits/stdc++.h>
using namespace std;
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int a[53]={4,10,20,35,56,83,116,155,198,244,292,341,390,439,488,537,586,635,684,733};
int main()
{
    int n=read();
    if(n<=20) printf("%d\n",a[n-1]);
    else printf("%lld\n",1LL*n*49-980+733);
    return 0;
}