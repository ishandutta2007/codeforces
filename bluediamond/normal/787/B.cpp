#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
bool miap[10005];
bool plap[10005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,j,k,a;
    bool ok=1;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>k;
        for(j=1;j<=k;j++)
        {
            cin>>a;
            if(a>0)
                plap[a]=1;
            else
                miap[-1*a]=1;
        }
        ok=0;
        for(j=1;j<=10000;j++)
        {
            if(plap[j]==miap[j] and plap[j])
                ok=1;
            plap[j]=miap[j]=0;
        }
        if(!ok)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}