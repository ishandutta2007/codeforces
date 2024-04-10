#include<bits/stdc++.h>
using namespace std;
int a[100003];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1; i<=n; i++) printf("%d ",a[i]);
        printf("\n");
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1; i<=n; i++) printf("%d ",a[i]);
    }
}