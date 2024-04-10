#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,a[N+5],st;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n),st=1;
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        while(st<=n && !a[st]) ++st;
        while(n>1)
        {
            for(int i=st==1?1:--st;i<n;++i) a[i]=a[i+1]-a[i];
            sort(a+st,a+(n--));
            while(st<=n && !a[st]) ++st;
        }
        printf("%d\n",a[1]);
    }
    return 0;
}