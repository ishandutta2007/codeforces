#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        char sy=s[n-1];
        for(int a=0; a<n; a++) cout<<sy;
        cout<<"\n";
    }
}