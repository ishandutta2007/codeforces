#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;

int n,m;
int a[N],b[N];
int v[N][N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        int h;
        cin>>h;
        for(int i=1;i<=m;i++)
        {
                cin>>b[i];
        }
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        cin>>v[i][j];
                }
        }
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        if(v[i][j]==1)
                        {
                                cout<<min(a[i],b[j])<<" ";
                        }
                        else
                        {
                                cout<<"0 ";
                        }
                }
                cout<<"\n";
        }
        return 0;
}
/**

**/