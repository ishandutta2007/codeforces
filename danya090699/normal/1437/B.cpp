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
        int an=0;
        for(int a=0; a+1<n; a++) an+=(s[a]==s[a+1]);
        cout<<an/2+(an%2)<<"\n";
    }
}