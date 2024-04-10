#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int q=0;
    for(int a=0; a<n; a++) if(s[a]=='z') q++;
    for(int a=0; a<(n-q*4)/3; a++) cout<<1<<" ";
    for(int a=0; a<q; a++) cout<<0<<" ";

}