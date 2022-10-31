#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int arr[maxn];
int pre[maxn];
int dp[maxn];
vector<int> all;
map<int,int> pos;
int getid(int x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
void print(int cur)
{
    if(cur==-1) return;
    print(pre[cur]);
    printf("%d ",cur+1);
}
int main()
{
    all.clear();
    int n;
    scanf("%d",&n);
    int ans=0;
    int ending=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        all.push_back(arr[i]);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(int i=0;i<n;i++)
    {
        int temp=0;
        int id=getid(arr[i]);
        if(pos.count(arr[i]-1)) temp=dp[getid(arr[i]-1)];
        dp[id]=temp+1;
        pos[arr[i]]=i;
        if(!temp) pre[i]=-1;
        else pre[i]=pos[arr[i]-1];
        if(ans<dp[id])
        {
            ans=dp[id];
            ending=i;
        }
    }
    printf("%d\n",ans);
    print(ending);
}