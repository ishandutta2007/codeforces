#include<bits/stdc++.h>
using namespace std;
const int N=15e4;
int a[N];
int main()
{
    int t,n,s,minx;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        s=0;
        minx=1000000;
        for(int i=n;i>=1;i--)
            if(minx<a[i])s++;
        else minx=a[i];
        printf("%d\n",s);
    }
    return 0;
}