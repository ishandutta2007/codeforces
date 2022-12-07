//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    bool go[26];
    for(int a=0; a<26; a++) go[a]=0;
    cin>>t;
    for(int a=0; a<t.size(); a++) go[t[a]-'a']=1;
    cin>>s;
    int n=s.size(), fo=-1, q;
    for(int a=0; a<s.size(); a++) if(s[a]=='*') fo=a;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        cin>>t;
        int m=t.size(), ok=1;
        if(fo==-1)
        {
            if(m!=n) ok=0;
            else
            {
                for(int b=0; b<n; b++)
                {
                    if(s[b]=='?')
                    {
                        if(go[t[b]-'a']==0) ok=0;
                    }
                    else if(s[b]!=t[b]) ok=0;
                }
            }
        }
        else
        {
            if(m<n-1) ok=0;
            else
            {
                int l=fo, r=fo+(m-(n-1));
                for(int b=0; b<m; b++)
                {
                    if(s[b]=='*') break;
                    else
                    {
                        if(s[b]=='?')
                        {
                            if(go[t[b]-'a']==0) ok=0;
                        }
                        else if(s[b]!=t[b]) ok=0;
                    }
                }
                for(int b=1; b<=m; b++)
                {
                    if(s[n-b]=='*') break;
                    else
                    {
                        if(s[n-b]=='?')
                        {
                            if(go[t[m-b]-'a']==0) ok=0;
                        }
                        else if(s[n-b]!=t[m-b]) ok=0;
                    }
                }
                for(int b=l; b<r; b++) if(go[t[b]-'a']) ok=0;
            }
        }
        if(ok) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}