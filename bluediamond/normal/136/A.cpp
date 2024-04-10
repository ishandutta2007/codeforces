#include <bits/stdc++.h>

using namespace std;

int n,v[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(v[j]==i)
                cout<<j<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

**/