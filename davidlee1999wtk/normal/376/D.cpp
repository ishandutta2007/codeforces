#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int cou[5005][5005]={0};
char t[5005];
int main()
{
    int n,m;
    int i,j,s;
    int ans=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        scanf("%s",t);
        s=0;
        for(j=0;j<m;j++)
        {
            if(t[j]=='0')
                s=j+1;
            else
                cou[s][j]++;
        }
    }
    for(i=2;i<m;i++)
        for(j=1;j<=i;j++)
            cou[j][i]+=cou[j-1][i];
    for(i=0;i<m;i++)
        for(j=i;j<m;j++)
            ans=max(ans,(j-i+1)*cou[i][j]);
    cout<<ans<<endl;
    return 0;
}