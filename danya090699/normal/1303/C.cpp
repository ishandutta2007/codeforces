#include <bits/stdc++.h>
using namespace std;
int sm[26][26], ok, us[26];
string an;
void dfs(int v, int pr)
{
    us[v]=1;
    an.push_back('a'+v);
    for(int a=0; a<26; a++)
    {
        if(a!=pr and sm[v][a]) dfs(a, v);
    }
}
main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t)
    {
        t--;
        string s;
        cin>>s;
        for(int a=0; a<26; a++) for(int b=0; b<26; b++) sm[a][b]=0;
        for(int a=0; a+1<s.size(); a++)
        {
            int u=s[a]-'a', v=s[a+1]-'a';
            sm[u][v]=1, sm[v][u]=1;
        }
        ok=1;
        an="";
        vector <int> sp;
        for(int a=0; a<26; a++)
        {
            int q=0;
            for(int b=0; b<26; b++) q+=sm[a][b];
            if(q>2) ok=0;
            if(q<2) sp.push_back(a);
            us[a]=0;
        }
        if(ok)
        {
            for(int a=0; a<sp.size(); a++)
            {
                int v=sp[a];
                if(!us[v]) dfs(v, v);
            }
            if(an.size()==26) cout<<"YES\n"<<an<<"\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }
}