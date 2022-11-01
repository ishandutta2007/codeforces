#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int res=0;
    int c[10]={6,2,5,5,4,5,6,3,7,6};
    for(int i=a;i<=b;i++)
    {
        int t=i;
        while(t)
        {
            res+=c[t%10];
            t/=10;
        }
    }
    printf("%d\n",res);
    return 0;
}