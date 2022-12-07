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
        int an=0, q1=0, q2=0;
        for(int a=0; a<n; a++)
        {
            if(s[a]=='<') q1++;
            if(s[a]=='>') q2++;

            if(s[a]=='-' or s[(a+1)%n]=='-') an++;
        }
        if(q1==0 or q2==0) an=n;
        cout<<an<<"\n";
    }
}