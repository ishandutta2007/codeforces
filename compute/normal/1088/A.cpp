#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int a,b;
    for(a=1;a<=x;a++)
    {
        for(b=1;b<=x;b++)
        {
            if(b%a==0&&a*b>x&&a/b<x)
            {
                cout<<b<<" "<<a<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}