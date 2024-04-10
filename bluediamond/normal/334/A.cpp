#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100;
int cnt=0;

int n,v[N+5][N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
            for(int j=1;j<=n;j++)
                v[j][i]=++cnt;
        else
            for(int j=n;j>=1;j--)
                v[j][i]=++cnt;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/**

**/