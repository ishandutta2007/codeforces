#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T
{
        int x;
        int y;
};

const int N=2000+7;
const int C=1000000+7;
int n;
int m;
T a[N];
T b[N];
int lim[C];

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>m;
        for (int i=1;i<=n;i++)
                cin>>a[i].x>>a[i].y;
        for (int i=1;i<=m;i++)
                cin>>b[i].x>>b[i].y;
        for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                {
                        int nx=b[j].x-a[i].x+1;
                        int ny=b[j].y-a[i].y+1;
                        if (nx<=0||ny<=0)
                                continue;
                        lim[nx-1]=max(lim[nx-1],ny);
                }
        int sol=C;
        for (int i=C-2;i>=0;i--)
        {
                lim[i]=max(lim[i+1],lim[i]);
                sol=min(sol,i+lim[i]);
        }
        cout<<sol<<"\n";
}