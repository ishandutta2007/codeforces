#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
long long num[200010];
long long pre[200010],suf[200010];
int main()
{
    int n,x,k;
    cin>>n>>x>>k;
    for(int i=1;i<=n;i++)
        scanf("%I64d",&num[i]);
    sort(num+1,num+n+1);
    for(int i=1;i<=n;i++)   
        pre[i]=pre[i-1]|num[i];
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]|num[i];
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long p=num[i];
        for(int j=1;j<=x;j++)
            p=p*k;
        ans=max(ans,pre[i-1]|suf[i+1]|p);
    }
    cout<<ans<<endl;
}