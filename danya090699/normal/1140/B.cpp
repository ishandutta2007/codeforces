#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        string s;
        cin>>n>>s;
        if(s[0]=='<' and s[n-1]=='>')
        {
            int an=1e9;
            for(int a=0; a<n; a++)
            {
                if(s[a]=='>')
                {
                    an=min(an, a);
                    break;
                }
            }
            for(int a=n-1; a>=0; a--)
            {
                if(s[a]=='<')
                {
                    an=min(an, n-a-1);
                    break;
                }
            }
            cout<<an<<"\n";
        }
        else cout<<0<<"\n";
    }
}