#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    string s, t;
    cin>>n>>s>>t;
    for(int a=0; a<n; a++)
    {
        if(s[a]!=t[a])
        {
            if(a+1<n)
            {
                if(s[a]!=s[a+1] and s[a+1]!=t[a+1]) a++;

            }
            an++;
        }
    }
    cout<<an;
}