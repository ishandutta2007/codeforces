#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;

pair<pair<int,int>,int>a[maxn];

int dp[maxn],pre[maxn];
void output(int n)
{
    if(n==0)return;
    output(pre[n]);
    printf("%d ",a[n].second);
}
int main()
{
    int n,w,h;
    scanf("%d%d%d",&n,&w,&h);
    int tot=0;
    
    a[tot++]=make_pair(make_pair(w,h),tot);
    
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>w && y>h)
            a[tot++]=make_pair(make_pair(x,y),i);
    }
    sort(a,a+tot);
    for(int i=0;i<tot;i++)
    {
    	for(int j=0;j<i;j++)
    	{
    		if(a[j].first.first < a[i].first.first && a[j].first.second < a[i].first.second && dp[i] < dp[j]+1)
            {
                dp[i]=dp[j]+1;
                pre[i]=j;// 
            }
		}
            
	}
        
    int where=0;
    for(int i=0;i<tot;i++)
        if(dp[where]<dp[i]) where=i;
        
    printf("%d\n",dp[where]); 
    output(where);
    return 0;
}