#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int h[N];
long long tree[N];
void add(int x,long long val)
{
    while(x<N)
    {
        tree[x]+=val;
        x+=x&-x;
    }
}
long long sum(int x)
{
    long long ret=0;
    while(x>0)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    memset(tree,0,sizeof(tree));
    int target=N;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
        target=min(target,h[i]);
    }
    sort(h,h+n);
    for(int i=1;i<=N;i++)
    {
        int num=n-(lower_bound(h,h+n,i)-h);
        add(i,num);
    }
    int ans=0;
    int pre=N;
    for(int i=N;i>target;i--)
    {
        if(sum(pre)-sum(i-1)>k)
        {
            ans++;
            pre=i;
        }
    }
    if(sum(pre)-sum(target)>0) ans++;
    printf("%d\n",ans);
    //system("pause");
}