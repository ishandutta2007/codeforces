#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mi=0, op=0, cl=0;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='(') op++;
        else cl++;
        mi=min(mi, op-cl);
    }
    if(op==cl and mi>=-1) cout<<"Yes";
    else cout<<"No";
}