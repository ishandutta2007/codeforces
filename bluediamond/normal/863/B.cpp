#include <iostream>
#include <algorithm>
using namespace std;
int v[105],sl[105];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,sol=9999999;
    cin>>n;
    for(int i=1;i<=2*n;i++)
        cin>>v[i];
    sort(v+1,v+2*n+1);
    for(int i=1;i<2*n;i++)
        for(int j=i+1;j<=2*n;j++)
        {
            int y=0;
            for(int i2=1;i2<=2*n;i2++)
                if(i2!=i and i2!=j)
                    sl[++y]=v[i2];
            int ma=0;
            for(int j2=1;j2<y;j2+=2)
                    ma+=sl[j2+1]-sl[j2];
            if(ma<sol)
                sol=ma;
        }
    cout<<sol;
    return 0;
}