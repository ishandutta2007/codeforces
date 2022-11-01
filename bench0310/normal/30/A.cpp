#include <bits/stdc++.h>

using namespace std;

int p(int b,int e)
{
    int res=1;
    for(int i=0;i<e;i++)
    {
        res*=b;
        if(res>1000||res<-1000) break;
    }
    return res;
}

int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    if(a==0)
    {
        if(b==0) printf("0\n");
        else printf("No solution\n");
    }
    else
    {
        if((b%a)!=0) printf("No solution\n");
        else
        {
            bool found=0;
            for(int x=-1000;x<=1000;x++)
            {
                if(p(x,n)==b/a)
                {
                    printf("%d\n",x);
                    found=1;
                    break;
                }
            }
            if(!found) printf("No solution\n");
        }
    }
    return 0;
}