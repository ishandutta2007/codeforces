#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,k,s[N+5];
inline bool check()
{
    if(k==1) return 1;
    for(int i=2;i<k;++i)
        if(s[i]>s[i+1]) return 0;
    return 1ll*s[2]*(n-k+1)>=s[1];
}
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=k;++i) scanf("%d",s+i);
        for(int i=k;i;--i) s[i]-=s[i-1];
        puts(check()?"Yes":"No");
    }
    return 0;
}