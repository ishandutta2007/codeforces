//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int qs[26], qt[26], qv=0;
    for(int a=0; a<26; a++)
    {
        qs[a]=0, qt[a]=0;
    }
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]=='?') qv++;
        else qs[s[a]-'a']++;
    }
    for(int a=0; a<t.size(); a++) qt[t[a]-'a']++;
    int n=s.size(), m=t.size();
    int l=0, r=n/m+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        int le=qv;
        for(int a=0; a<26; a++)
        {
            if(qs[a]<qt[a]*mid) le-=qt[a]*mid-qs[a];
        }
        if(le>=0) l=mid;
        else r=mid;
    }
    int add[26];
    for(int a=0; a<26; a++)
    {
        if(qs[a]<qt[a]*l) add[a]=qt[a]*l-qs[a];
        else add[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        if(s[a]!='?') cout<<s[a];
        else
        {
            bool fo=0;
            for(int b=0; b<26; b++)
            {
                if(add[b]>0)
                {
                    fo=1, add[b]--;
                    char sy='a'+b;
                    cout<<sy;
                    break;
                }
            }
            if(fo==0) cout<<'a';
        }
    }
}