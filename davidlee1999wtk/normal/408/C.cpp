#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
typedef long long LL;
int main()
{
    int a,b,i,j,c1=0,c2=0,k,d1,d2;
    cin>>a>>b;
    k=__gcd(a,b);
    if(a>b) swap(a,b);
    d1=a/k; d2=b/k;
    for(i=1;i<=k;i++)
        for(j=i;j<=k;j++)
            if(i*i+j*j==k*k)
            {
                c1=i; c2=j; i=k+1;
                break;
            }
    //cout<<k<<' '<<c1<<' '<<c2<<endl;
    if(c1==0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("0 0\n");
    if(c1*d1!=d2*c2&&c2*d1!=d2*c1)
    {
        printf("-%d %d\n",c1*d1,c2*d1);
        printf("%d %d\n",d2*c2,d2*c1);
    }
    else
    {
        printf("-%d %d\n",c2*d1,c1*d1);
        printf("%d %d\n",d2*c1,d2*c2);
    }
    return 0;
}
// davidlee1999WTK 2014/