#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n ;a++)
    {
        for(int b=0; b<n; b++)
        {
            if((a+b)&1) cout<<"W";
            else cout<<"B";
        }
        cout<<"\n";
    }
}