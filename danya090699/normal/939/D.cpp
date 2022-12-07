#include <bits/stdc++.h>
using namespace std;
bool sm[26][26], us[26];
vector <int> sp;
vector <pair <char, char> > an;
void dfs(int v)
{
    us[v]=1, sp.push_back(v);
    for(int a=0; a<26; a++) if(sm[v][a] and us[a]==0) dfs(a);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s, t;
    cin>>n>>s>>t;
    for(int a=0; a<n; a++)
    {
        sm[s[a]-'a'][t[a]-'a']=1;
        sm[t[a]-'a'][s[a]-'a']=1;
    }
    for(int a=0; a<26; a++)
    {
        if(us[a]==0)
        {
            dfs(a);
            for(int b=0; b<sp.size()-1; b++) an.push_back(make_pair(sp[b]+'a', sp[b+1]+'a'));
            sp.clear();
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
}