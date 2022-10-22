#include<bits/stdc++.h>
#define N 100
const int inf=2e9;
using namespace std;
int T,n,a[N+5],b[N+5],s[N+5],f[N+5][N*N+5];
inline void mina(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",a+i),sum+=a[i]*a[i]*(n-1);
        for(int i=1;i<=n;++i) scanf("%d",b+i),sum+=b[i]*b[i]*(n-1);
        for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i]+b[i];
        for(int i=0;i<=n;++i)
            for(int j=0;j<=s[i];++j)
                f[i][j]=inf;
        f[0][0]=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<=s[i];++j) if(f[i][j]!=inf)
            {
                mina(f[i+1][j+a[i+1]],f[i][j]+j*a[i+1]+(s[i]-j)*b[i+1]);
                mina(f[i+1][j+b[i+1]],f[i][j]+j*b[i+1]+(s[i]-j)*a[i+1]);
            }
        int minn=inf;
        for(int i=0;i<=s[n];++i) mina(minn,f[n][i]);
        printf("%d\n",sum+2*minn);
    }
    return 0;
}