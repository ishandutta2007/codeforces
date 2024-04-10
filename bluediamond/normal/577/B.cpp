#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <iostream>

using namespace std;

const int N=1000+5;

int n,m;
int f[N];
bool ok[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        f[x%m]++;
    }
    if(f[0])
    {
        ok[0][0]=1;
    }
    for(int i=1;i<m;i++)
    {
        if(f[i]>=m)
        {
            cout<<"YES\n";
            return 0;
        }
        for(int take=1;take<=f[i];take++)
        {
            ok[i][(take*i)%m]=1;
        }
        if(f[i]>100) f[i]=100;
        for(int j=0;j<m;j++)
        {
            if(ok[i-1][j])
            {
                ok[i][j]=1;
                for(int take=1;take<=f[i];take++)
                {
                    ok[i][(j+take*i)%m]=1;
                }
            }
        }
    }
    if(ok[m-1][0])
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}
/**


**/