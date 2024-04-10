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
int A[1000003],B[1000003];
signed main()
{
	int n=read(),m=read(),a=read(),b=read(),k=read();
    for(int i=1; i<=n; i++) A[i]=read();
    for(int i=1; i<=m; i++) B[i]=read()-a;
    int ans=0ll;
    if(k>=n||k>=m)
    {
        puts("-1");
        return 0;}
    for(int i=1,j=k; j>=0; i++,--j)  
    {
        int pos=lower_bound(B+1,B+m+1,A[i])-B;
        if(j>=m-pos+1) 
        {
            puts("-1");
            return 0;
        }
        ans=max(ans,B[pos+j]);
    }
    printf("%lld\n",ans+a+b);
	return 0;
}