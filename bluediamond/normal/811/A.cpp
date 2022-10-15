#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int a,b,i=1,s=0,poz=1;
    cin>>a>>b;
    while(1)
    {
        if(poz==1)
        {
            if(a<i)
            {
                cout<<"Vladik";
                return 0;
            }
            a-=i;
        }
        if(poz==2)
        {
            if(b<i)
            {
                cout<<"Valera";
                return 0;
            }
            b-=i;
        }
        poz=3-poz;
        i++;
    }
    return 0;
}