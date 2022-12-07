#include <bits/stdc++.h>
using namespace std;
const int sz=20;
bool sm[sz][sz], us[sz];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sz; a++)
    {
        if(sm[v][a] and !us[a]) dfs(a);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, ok=1;
        cin>>n;
        string s, t;
        cin>>s>>t;
        for(int a=0; a<sz; a++)
        {
            us[a]=0;
            for(int b=0; b<sz; b++) sm[a][b]=0;
        }
        for(int a=0; a<n; a++)
        {
            if(s[a]<t[a])
            {
                sm[s[a]-'a'][t[a]-'a']=1;
                sm[t[a]-'a'][s[a]-'a']=1;
            }
            if(t[a]<s[a]) ok=0;
        }
        if(ok)
        {
            int an=sz;
            for(int a=0; a<sz; a++)
            {
                if(!us[a]) an--, dfs(a);
            }
            cout<<an<<"\n";
        }
        else cout<<"-1\n";
    }
}