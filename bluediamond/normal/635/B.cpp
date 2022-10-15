#include <iostream>
using namespace std;
int v1[200005];
int v2[200005];
int f(int poz,int n)
{
    if(poz<=n)
        return poz;
    else
        return poz-n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,y1=0,y2=0,y,j;
    bool e0=0;
    cin>>n;
    for(i=1;i<=n;i++)
        {
        cin>>y;
        if(y)
            v1[++y1]=y;
        }
    for(i=1;i<=n;i++)
        {
        cin>>y;
        if(y)
            v2[++y2]=y;
        }
    y=y1;
    if(y1!=y2)
    {
        cout<<"NO";
        return 0;
    }
    for(i=1;i<=y;i++)
    {
        bool ok=1;
        for(j=1;j<=y;j++)
            if(v1[j]!=v2[f(j+i-1,y)])
            {
                ok=0;
                break;
            }
        if(ok)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}