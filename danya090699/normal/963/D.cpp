#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
struct el
{
    int pr=0, link=0, nu=-1, link2=0, prsy;
};
el bor[sz];
int ne[sz][26], go[sz][26], q=1;
vector <int> sp[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n;
    cin>>n;
    int le[n], k[n];
    for(int a=0; a<26; a++)
    {
        ne[0][a]=-1, go[0][a]=0;
    }
    for(int a=0; a<n; a++)
    {
        string t;
        cin>>k[a]>>t;
        le[a]=t.size();
        int cu=0;
        for(int b=0; b<le[a]; b++)
        {
            int sy=t[b]-'a';
            if(ne[cu][sy]==-1)
            {
                ne[cu][sy]=q, bor[q].pr=cu, bor[q].prsy=sy;
                for(int c=0; c<26; c++) ne[q][c]=-1;
                q++;
            }
            cu=ne[cu][sy];
        }
        bor[cu].nu=a;
    }
    queue <int> qu;
    qu.push(0);
    while(qu.size())
    {
        int qq=qu.size();
        for(int a=0; a<qq; a++)
        {
            int cu=qu.front();
            int pr=bor[cu].pr, prsy=bor[cu].prsy;
            if(cu!=0 and pr!=0)
            {
                bor[cu].link=go[bor[pr].link][prsy];
                if(bor[bor[cu].link].nu!=-1) bor[cu].link2=bor[cu].link;
                else bor[cu].link2=bor[bor[cu].link].link2;
            }
            for(int b=0; b<26; b++)
            {
                if(ne[cu][b]!=-1)
                {
                    go[cu][b]=ne[cu][b];
                    qu.push(ne[cu][b]);
                }
                else go[cu][b]=go[bor[cu].link][b];
            }
            qu.pop();
        }
    }
    int cu=0;
    for(int a=0; a<s.size(); a++)
    {
        cu=go[cu][s[a]-'a'];
        int x=cu;
        while(x!=0)
        {
            if(bor[x].nu!=-1) sp[bor[x].nu].push_back(a);
            x=bor[x].link2;
        }
    }
    for(int a=0; a<n; a++)
    {
        if(sp[a].size()<k[a]) cout<<"-1\n";
        else
        {
            int be=1e9;
            for(int b=k[a]-1; b<sp[a].size(); b++) be=min(be, sp[a][b]-sp[a][b-k[a]+1]+le[a]);
            cout<<be<<"\n";
        }
    }
}