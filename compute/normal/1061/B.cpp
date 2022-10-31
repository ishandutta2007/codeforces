#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int main()
{
    int n,m;
    long long all=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        all+=arr[i];
    }
    int base=0;
    long long ans=0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]>base)
            base++;
    }
    ans=base;
    ans+=arr[n-1]-base;
    if(base<n)
        ans+=n-base;
    printf("%lld\n",all-ans);
}