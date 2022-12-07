#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<3) cout<<"No";
    else
    {
        cout<<"Yes\n";
        if(n&1)
        {
            cout<<1<<" "<<n/2+1<<"\n";
            cout<<n-1<<" ";
            for(int a=1; a<=n; a++) if(a!=n/2+1) cout<<a<<" ";
        }
        else
        {
            cout<<2<<" "<<n/2<<" "<<n/2+1<<"\n";
            cout<<n-2<<" ";
            for(int a=1; a<=n; a++) if(a!=n/2 and a!=n/2+1) cout<<a<<" ";
        }
    }
}