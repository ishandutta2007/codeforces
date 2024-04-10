#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define INF 100000000
using namespace std;
int a[105],n,used[105]={0};
int main()
{
    int i,ans=0,h=101,she;
    cin>>n; she=n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    while(she)
    {
        ans++; h=0;
        for(i=1;i<=n;i++)
        {
            if(used[i])
                continue;
            if(a[i]<h)
                continue;
            h++;
            used[i]=1;
            she--;
        }
    }
    cout<<ans<<endl;
    return 0;
}