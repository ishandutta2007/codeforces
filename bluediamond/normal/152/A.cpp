#include <iostream>
#include <algorithm>
using namespace std;
int v[105][105],ma[105];
bool wi[105];
int main()
{
    int n,m,i,j,s=0;char ch;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin.get();
        for(j=1;j<=m;j++)
        {
            ch=cin.get();
            v[i][j]=ch-'0';
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            ma[j]=max(ma[j],v[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(v[i][j]==ma[j])
                wi[i]=1;
    for(i=1;i<=n;i++)
        s+=wi[i];
    cout<<s;
    return 0;
}