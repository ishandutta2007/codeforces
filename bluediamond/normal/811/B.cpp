#include <iostream>
#include <algorithm>
using namespace std;
int n,m,i,j,st,dr,x;
int v[10005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(i=1;i<=m;i++)
    {
        cin>>st>>dr>>x;
        int s=0;
        for(j=st;j<=dr;j++)
            if(v[j]<v[x])
                s++;
        if(s==x-st)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}