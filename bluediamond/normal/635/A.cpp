#include <iostream>
using namespace std;
bool v[15][15];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k,i,j,x,r,c,i2,j2;
    long long s=0;
    cin>>n>>m>>x>>k;
    for(i=1;i<=x;i++)
    {
        cin>>r>>c;
        v[r][c]=1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            /// i i+r-1
            /// j c+j-1
            for(r=1;i+r-1<=n;r++)
                for(c=1;j+c-1<=m;c++)
                {
                    int s2=0;
                    for(i2=i;i2<=i+r-1;i2++)
                        for(j2=j;j2<=j+c-1;j2++)
                            s2+=v[i2][j2];
                    if(s2>=k)
                        s++;
                }
        }
    cout<<s;
    return 0;
}