#include <iostream>

using namespace std;
long long n, m, a[15][100005], pos[15][100005], ans, k, p[15];
bool f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
    {
        cin >> a[i][j];
        pos[i][a[i][j]]=j;
    }
    ans=0;
    int x=0;
    while(x<n)
    {
        for(int j=0;j<m;j++)
            p[j]=pos[j][a[0][x]];
        f=true;
        k=0;
        while(f)
        {
            k++;
            for(int i=0;i<m;i++)
                if(p[i]+k>=n || a[i][p[i]+k]!=a[0][x+k])
                {
                    f=false;
                }
        }
        ans+=k*(k+1)/2;
        x+=k;
    }
    cout << ans;
    return 0;
}