#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q[2]={0, 0}, su[2]={0, 0};
    string s;
    cin>>n>>s;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='?') q[a/(n/2)]++;
        else su[a/(n/2)]+=s[a]-'0';
    }
    if(su[0]*2+q[0]*9==su[1]*2+q[1]*9) cout<<"Bicarp";
    else cout<<"Monocarp";
}