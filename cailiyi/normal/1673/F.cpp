#include<bits/stdc++.h>
#define N 32
#define id(i,j) (i*n+j)
using namespace std;
int n,k,val,sum,a[N],id[N][N],x[N*N],y[N*N];
int main()
{
    for(int i=1;i<N;++i) a[i]=a[i-1]^(i&-i);
    scanf("%d %d",&n,&k);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
            for(int k=0;k<5;++k)
                id[i][j]|=(((a[i]>>k)&1)<<(k<<1))|(((a[j]>>k)&1)<<(k<<1|1));
            x[id[i][j]]=i,y[id[i][j]]=j;
        }
    for(int i=0;i<n;++i) for(int j=0;j<n-1;++j)
        printf("%d%c",id[i][j]^id[i][j+1]," \n"[j==n-2]);
    for(int i=0;i<n-1;++i) for(int j=0;j<n;++j)
        printf("%d%c",id[i][j]^id[i+1][j]," \n"[j==n-1]);
    fflush(stdout);
    while(k--)
    {
        scanf("%d",&val),sum^=val;
        printf("%d %d\n",x[sum]+1,y[sum]+1);
        fflush(stdout);
    }
    return 0;
}