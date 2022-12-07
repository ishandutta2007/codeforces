#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> sv[sz];
bool us[sz];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
char s[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%s", s);
        for(int b=0; s[b]; b++)
        {
            sv[a+26].push_back(s[b]-'a');
            sv[s[b]-'a'].push_back(a+26);
        }
    }
    int an=0;
    for(int a=26; a<n+26; a++)
    {
        if(us[a]==0) dfs(a), an++;
    }
    cout<<an;
}