#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int q1=0, q2=0, an=0;
        for(int a=0; a<s.size(); a++)
        {
            if(s[a]=='(') q1++;
            if(s[a]==')')
            {
                if(q1) q1--, an++;
            }
            if(s[a]=='[') q2++;
            if(s[a]==']')
            {
                if(q2) q2--, an++;
            }
        }
        cout<<an<<"\n";
    }
}