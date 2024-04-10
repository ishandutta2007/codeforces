#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
int a[3005],b[3005];
int main()
{
    int n,m,i,c1,c2,ans=0;
    cin>>n>>m; ans=n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(a+1,a+n+1); sort(b+1,b+m+1);
    c1=n; c2=m;
    while(c1&&c2)
    {
        if(b[c2]>=a[c1])
        {
            c1--; c2--; ans--;
        }
        else
            c1--;
    }
    cout<<ans<<endl;
    return 0;
}