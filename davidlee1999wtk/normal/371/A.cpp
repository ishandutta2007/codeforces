#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
int n,k,a[105],cou[105][3]={0};
int main()
{
    int i,j;
    int ans=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=k;i++)
        for(j=1;j<=n/k;j++)
            cou[i][a[(j-1)*k+i]]++;
    for(i=1;i<=k;i++)
        ans+=min(cou[i][1],cou[i][2]);
    cout<<ans<<endl;
    return 0;
}