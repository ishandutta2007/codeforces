#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,a,s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        s+=a;
    }
    if(n==1)
    {
        if(s==1)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    if(s==n-1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}