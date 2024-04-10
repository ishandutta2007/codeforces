#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch&15),ch=getchar();
    return x;
}

signed main()
{
	int a=read(),b=read(),c=read();
    printf("%lld\n",max(c*2+min(a,b)*2+(a>b),(b==0)*-10000000001000ll+1+c*2+min(a,b-1)*2+(a>b-1)));
	return 0;
}