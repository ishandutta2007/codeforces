#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n,m;
int v[11][N];
int poz[11][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>v[i][j];
            poz[i][v[i][j]]=j;
        }
    }
    ll ans=0LL;
    int i=1;
    while(i<=n)
    {
        int j=i;
        while(j+1<=n)
        {
            j++;
            bool ok=1;
            for(int k=2;k<=m;k++)
            {
                if(poz[k][v[1][j]]-poz[k][v[1][j-1]]!=1)
                {
                    ok=0;
                    break;
                }
            }
            if(ok==0)
            {
                j--;
                break;
            }
        }
        ll l=j-i+1;
        ans+=l*(l+1)/2;
        i=j+1;
    }
    cout<<ans<<"\n";
    return 0;
}
/**



**/