#include <iostream>
using namespace std;
int v1,v2,v3,vm;
int main()
{
    cin>>v1>>v2>>v3>>vm;
    for(int i=v1;i<=2*v1;i++)
        for(int j=v2;j<=2*v2;j++)
            for(int k=v3;k<=2*v3;k++)
            {
                if(i>j and j>k and vm<=i and vm<=j and vm<=k)
                {
                    if(i>2*vm and j>2*vm and k<=2*vm)
                    {
                        cout<<i<<"\n"<<j<<"\n"<<k;
                        return 0;
                    }
                }
            }
    cout<<-1;
    return 0;
}