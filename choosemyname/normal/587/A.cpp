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
int hv[2000010];
int main()
{
    int n,n1,t1;
    cin>>n;
    for(n1=1;n1<=n;n1++)
    {
        scanf("%d",&t1);
        while(hv[t1]==1)
        {
            hv[t1]=0;
            t1++;
        }
        hv[t1]=1;
    }
    int ans=0;
    for(n1=0;n1<=2000000;n1++)
        if(hv[n1])
            ans++;
    cout<<ans;
}