#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,m,k,a[N+5],b[N+5];
inline bool check(int num)
{
    long long sum=0;bool flag=0;
    for(int i=1;i<=k;++i) if(b[i]>1)
        sum+=b[i],flag|=b[i]>2;
    if(sum<num) return 0;
    if(!flag && num&1) return 0;
    return 1;
}
inline bool check()
{
    for(int i=1;i<=k;++i) b[i]=a[i]/m;
    if(check(n)) return 1;
    for(int i=1;i<=k;++i) b[i]=a[i]/n;
    if(check(m)) return 1;
    return 0;
}
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=k;++i) scanf("%d",a+i);
        puts(check()?"Yes":"No");
    }
    return 0;
}