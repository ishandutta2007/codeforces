#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int maxn=4000000;
#define int long long
const int inf=(int)1e13;
int n,a[maxn],b[N],cnt=0,ans[N];

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n/2;i++) scanf("%lld",&b[i]);
    for(int i=1;i*i<=inf;i++) a[++cnt]=i*i;
    int i=0,now=1;
    while(i<=cnt&&now<=n/2)
    {
        int pre=a[i]; i++;
        //cout<<i<<" "<<a[i]<<endl;
        while(i<=cnt)
        {
            int pos=lower_bound(a+1,a+cnt+1,a[i]+b[now])-a;
            if(a[pos]==a[i]+b[now]) 
            {
                ans[now]=a[i]-pre; now++;
                i=pos;
                break;
            }
            i++;
        }
        //cout<<i<<endl;
    }
    //cout<<"OK"<<endl;
    if(now>n/2)
    {
        puts("Yes");
        for(i=1;i<=n/2;i++) printf("%lld %lld ",ans[i],b[i]);
        puts("");
    }
    else puts("No");
    return 0;
}