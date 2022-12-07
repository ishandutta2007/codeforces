#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int l=0, r=0, n=s.size();
    long long an=0;
    for(int a=0; a+1<n; a++) if(s[a]=='v' and s[a+1]=='v') r++;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='o') an+=(1ll*l*r);
        else
        {
            if(a and s[a-1]=='v') l++, r--;
        }
    }
    cout<<an;
}