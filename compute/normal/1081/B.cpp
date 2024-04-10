#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int ans[maxn];
int all[maxn];
vector<int> col[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    memset(arr,0,sizeof(arr));
    for(int i=0,temp;i<n;i++)
    {
        scanf("%d",&arr[i]);
        arr[i]=n-arr[i];
        all[arr[i]]++;
        col[arr[i]].push_back(i+1);
    }
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(all[i]%i)
            flag=1;
    }
    if(flag) puts("Impossible");
    else{
        puts("Possible");
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<col[i].size();j++)
            {
                int now=col[i][j];
                ans[now]=cnt+j/i;
            }
            cnt+=col[i].size()/i;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
    }
}