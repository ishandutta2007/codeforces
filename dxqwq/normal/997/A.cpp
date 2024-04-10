#include<bits/stdc++.h>
using namespace std;
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
char ch[1000003];
int main()
{
    int n=read();
    long long x=read(),y=read();
    long long ans=0;
    scanf("%s",ch);
    bool f=0;
    int xx=0;
    for(int i=1; i<n; i++) if(ch[i]!=ch[i-1] && ch[i]=='0') ++xx;
    if(ch[0]=='0') ++xx;
    if(xx==0) puts("0"),exit(0);
    ans=1LL*min(x,y)*(xx-1)+y;
    printf("%lld\n",ans);
    return 0;
}