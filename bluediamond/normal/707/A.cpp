#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>a;
            if(a!="B" and a!="W" and a!="G")
            {
                cout<<"#Color";
                return 0;
            }
        }
    cout<<"#Black&White";
    return 0;
}