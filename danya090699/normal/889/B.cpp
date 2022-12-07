#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, to[26], pr[26], us[26], ok=1;
    cin>>n;
    for(int a=0; a<26; a++)
    {
        to[a]=-1, us[a]=0, pr[a]=0;
    }
    set <char> se;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int m=s.size();
        for(int a=0; a<m-1; a++)
        {
            int sy=s[a]-'a', sy2=s[a+1]-'a';
            if(to[sy]==-1 or to[sy]==sy2)
            {
                pr[sy2]=1;
                to[s[a]-'a']=s[a+1]-'a';
            }
            else ok=0;
            se.insert(s[a]);
        }
        se.insert(s[m-1]);
    }
    string s;
    for(int a=0; a<26; a++)
    {
        if(se.find('a'+a)!=se.end() and pr[a]==0)
        {
            int v=a;
            while(v!=-1)
            {
                if(us[v])
                {
                    ok=0;
                    break;
                }
                else
                {
                    s.push_back('a'+v);
                    us[v]=1, v=to[v];
                }
            }
        }
    }
    if(ok and se.size()==s.size()) cout<<s;
    else cout<<"NO";
}