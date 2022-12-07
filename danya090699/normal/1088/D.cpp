#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c=0, d=0, re, va;
    cout<<"? "<<c<<" "<<d<<endl;
    cin>>va;
    for(int i=29; i>=0; i--)
    {
        cout<<"? "<<c+(1<<i)<<" "<<d+(1<<i)<<endl;
        cin>>re;
        if(re!=va)
        {
            if(va==1) c+=(1<<i);
            else d+=(1<<i);
            cout<<"? "<<c<<" "<<d<<endl;
            cin>>va;
        }
        else
        {
            cout<<"? "<<c+(1<<i)<<" "<<d<<endl;
            cin>>re;
            if(re==-1) c+=(1<<i), d+=(1<<i);
        }
    }
    cout<<"! "<<c<<" "<<d<<endl;
}