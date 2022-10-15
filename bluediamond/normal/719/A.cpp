#include <bits/stdc++.h>

using namespace std;

int n,v[100],a,b;

int main()
{
    cin>>n;
    if(n==1)
    {
        int a;
        cin>>a;
        if(a==15)
            cout<<"DOWN";
        if(a==0)
            cout<<"UP";
        if(a!=0 and a!=15)
            cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>v[i];
    a=v[n-1];
    b=v[n];
    if(a+1==b)
    {
        if(b==15)
            cout<<"DOWN";
        else
            cout<<"UP";
        return 0;
    }
    if(a-1==b)
    {
        if(b==0)
            cout<<"UP";
        else
            cout<<"DOWN";
    }///error
    return 0;
}
/**


**/