#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        bool ok=0;
        for(int a=0;a<7;a++)
            if(3*a<=x and (3*a)%7==x%7)
                ok=1;
        if(ok==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}