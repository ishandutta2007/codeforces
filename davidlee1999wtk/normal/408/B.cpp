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
using namespace std;
typedef long long LL;
char hv[1005],nd[1005];
int c1[300],c2[300];
int main()
{
    int ans=0,i,n,m;
    scanf("%s%s",hv,nd);
    n=strlen(hv); m=strlen(nd);
    for(i=0;i<n;i++)
        c1[hv[i]]++;
    for(i=0;i<m;i++)
        c2[nd[i]]++;
    for(i=1;i<300;i++)
    {
        if(c2[i]>0&&c1[i]==0)
        {
            printf("-1\n");
            return 0;
        }
        ans+=min(c1[i],c2[i]);
    }
    cout<<ans<<endl;
    return 0;
}