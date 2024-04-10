#include<bits/stdc++.h>
#define N 100000
int T,n,a[N+5],q;
char s[N+5];
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&q),s[n+1]=0;
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=n,now=0;i;--i)
            if(a[i]>now) now<q?++now,s[i]='1':s[i]='0';
            else s[i]='1';
        puts(s+1);
    }
    return 0; 
}