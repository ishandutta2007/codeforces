#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=26, an=0;
    cin>>n;
    int us[26];
    for(int a=0; a<26; a++) us[a]=1;
    for(int a=0; a<n-1; a++)
    {
        char sy;
        string s;
        cin>>sy>>s;
        if(q==1)
        {
            if(sy=='!' or sy=='?') an++;
        }
        else
        {
            if(sy=='!')
            {
                bool us2[26];
                for(int b=0; b<26; b++) us2[b]=0;
                for(int b=0; b<s.size(); b++) us2[s[b]-'a']=1;
                for(int b=0; b<26; b++)
                {
                    if(us2[b]==0 and us[b])
                    {
                        us[b]=0, q--;
                    }
                }
            }
            else if(sy=='.')
            {
                for(int b=0; b<s.size(); b++)
                {
                    if(us[s[b]-'a'])
                    {
                        us[s[b]-'a']=0, q--;
                    }
                }
            }
            else
            {
                if(us[s[0]-'a'])
                {
                    us[s[0]-'a']=0, q--;
                }
            }
        }
    }
    cout<<an;
}