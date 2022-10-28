#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int c[1000005],a[1000005],n;
map<int,int> ml,mr;
void Add(int x,int k)
{
    for(;x<=n&&x;x+=x&-x)
        c[x]+=k;
}
int Get(int x)
{
    int sum=0;
    for(;x;x-=x&-x)
        sum+=c[x];
    return sum;
}
int main()
{
    int i;
    LL ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=n;i>1;i--)
    {
        mr[a[i]]++;
        Add(mr[a[i]],1);
    }
    for(i=1;i<n;i++)
    {
        ml[a[i]]++;
        ans+=Get(ml[a[i]]-1);
        Add(mr[a[i+1]],-1);
        //Add(mr[a[i]]-1,1);
        mr[a[i+1]]--;
    }
    cout<<ans<<endl;
    return 0;
}