#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int n=s.size(), m=t.size(), su=0, cu=0, an=0, yk=0;
    for(int a=0; a<m; a++) su^=(t[a]-'0');
    for(int a=0; a+m<=n; a++)
    {
        while(yk<a+m) cu^=(s[yk]-'0'), yk++;
        if(cu==su) an++;
        cu^=(s[a]-'0');
    }
    cout<<an;
}