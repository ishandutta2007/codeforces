#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), r=n;
    long long an=0;
    for(int a=n-1; a>=0; a--)
    {
        for(int d=1; (a+d*2<r); d++) if(s[a]==s[a+d] and s[a+d]==s[a+d*2]) r=a+d*2;
        an+=n-r;
    }
    cout<<an;
}