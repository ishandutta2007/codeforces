#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,m;
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&m);
        if(m<n) puts("No");
        else if(n&1)
        {
            puts("Yes");
            for(int i=1;i<n;++i) printf("1 ");
            printf("%d\n",m-(n-1));
        }
        else if(m&1) puts("No");
        else
        {
            puts("Yes");
            for(int i=1;i<n-1;++i) printf("1 ");
            int val=(m-(n-2))/2;
            printf("%d %d\n",val,val);
        }
    }
    return 0;
}