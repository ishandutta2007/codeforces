#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0;
    string s;
    cin>>n>>s;
    long long an=1ll*n*(n-1)/2;
    while(yk<n)
    {
        //cout<<yk<<" ";
        int st=yk;
        while(yk<n and s[yk]==s[st]) yk++;
        if(st) an-=yk-st;
        if(yk<n) an-=yk-st-1;
    }
    cout<<an;
}