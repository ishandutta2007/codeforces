//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s1, s2, t;
    cin>>s1>>s2>>t;
    int po[26];
    for(int a=0; a<26; a++) po[s1[a]-'a']=a;
    for(int a=0; a<t.size(); a++)
    {
        if(('A'<=t[a] and t[a]<='Z') or ('a'<=t[a] and t[a]<='z'))
        {
            char sy=t[a], bg=0;
            if(sy<'a')
            {
                sy+=32, bg=1;
            }
            sy=s2[po[sy-'a']];
            if(bg) sy-=32;
            cout<<sy;
        }
        else cout<<t[a];
    }
}