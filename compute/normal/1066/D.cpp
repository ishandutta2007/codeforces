#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int arr[maxn];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    long long now=0;
    int box=1;
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        if(now+arr[i]>k)
        {
            box++;
            if(box==m+1) break;
            now=0;
        }
        now+=arr[i];
        ans++;
    }
    printf("%d\n",ans);
}