#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++) cout<<a*2+1+(a&1)<<" ";
        for(int a=0; a<n; a++) cout<<a*2+2-(a&1)<<" ";
    }
    else cout<<"NO";
}