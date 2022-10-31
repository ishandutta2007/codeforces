#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int vis[105];
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    int cnt=0;
    int le,ri;
    for(int i=0;i<n;i++)
    {
        cin>>le>>ri;
        for(int j=le;j<=ri;j++)
            vis[j]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(!vis[i])
            cnt++;
    }
    cout<<cnt<<endl;
    int first=1;
    for(int i=1;i<=m;i++)
    {
        if(!vis[i])
        {
            if(first)
            {
                cout<<i;
                first =0;
            }
            else printf(" %d",i);
        }
    }
    cout<<endl;
    return 0;

}