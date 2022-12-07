#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, su=0, an=0;
    cin>>n;
    string s;
    cin>>s;
    for(int a=0; a<n; a++)
    {
        int add=(s[a]=='(') ? 1 : -1;
        if(su<0 or su+add<0) an++;
        su+=add;
    }
    if(su==0) cout<<an;
    else cout<<-1;
}