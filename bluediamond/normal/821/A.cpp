#include <iostream>
using namespace std;
int v[55][55];
int main()
{
    int n,i,j,r,c;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>v[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(v[i][j]!=1)
                {
                bool ok=0;
                for(r=1;r<=n;r++)
                    {
                    for(c=1;c<=n;c++)
                        if(v[i][j]==v[i][c]+v[r][j])
                        {
                            ok=1;
                            break;
                        }
                    if(ok)
                        break;
                    }
                if(!ok)
                {
                    cout<<"No";
                    return 0;
                }
                }
    cout<<"Yes";
    return 0;
}