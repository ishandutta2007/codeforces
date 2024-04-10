#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll v[5][15],n,pot[1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=6;j++)
            cin>>v[i][j];
    ///1 zar
    for(int i=1;i<=n;i++)
        for(int j=1;j<=6;j++)
            pot[v[i][j]]=1;
    ///2 zar
    for(int i1=1;i1<=n;i1++)
    for(int i2=1;i2<=n;i2++)
        if(i1!=i2)
        {
            for(int j1=1;j1<=6;j1++)
            for(int j2=1;j2<=6;j2++)
                if(v[i1][j1]!=0)pot[v[i1][j1]*10+v[i2][j2]]=1;
        }
    ///3 zar
    for(int i1=1;i1<=n;i1++)
    for(int i2=1;i2<=n;i2++)
    for(int i3=1;i3<=n;i3++)
        if(i1!=i2 and i1!=i3)
        {
            for(int j1=1;j1<=6;j1++)
            for(int j2=1;j2<=6;j2++)
            for(int j3=1;j3<=6;j3++)
                {
                    if(v[i1][j1]!=0)
                    pot[100*v[i1][j1]+10*v[i2][j2]+v[i3][j3]]=1;
                }
        }
    for(int i=1;i<=1000;i++)
        if(pot[i]==0)
        {
            cout<<i-1;
            return 0;
        }
    return 0;
}
/**

**/