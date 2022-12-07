#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
struct el
{
    int pr=0, link=0, nu=-1, link2=0, q=0, prsy;
};
el bor[sz];
int ne[sz][26], go[sz][26], q=1;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n;
    cin>>n;
    string ar[n];
    for(int a=0; a<26; a++)
    {
        ne[0][a]=-1, go[0][a]=0;
    }
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        int cu=0;
        for(int b=0; b<ar[a].size(); b++)
        {
            int sy=ar[a][b]-'a';
            if(ne[cu][sy]==-1)
            {
                ne[cu][sy]=q, bor[q].pr=cu, bor[q].prsy=sy;
                for(int c=0; c<26; c++) ne[q][c]=-1;
                q++;
            }
            cu=ne[cu][sy];
        }
        bor[cu].nu=a;
        bor[cu].q++;
    }
    queue <int> qu;
    qu.push(0);
    while(qu.size())
    {
        int cu=qu.front();
        int pr=bor[cu].pr, prsy=bor[cu].prsy;
        if(cu!=0 and pr!=0)
        {
            bor[cu].link=go[bor[pr].link][prsy];
            if(bor[bor[cu].link].nu!=-1) bor[cu].link2=bor[cu].link;
            else bor[cu].link2=bor[bor[cu].link].link2;
        }
        for(int a=0; a<26; a++)
        {
            if(ne[cu][a]!=-1)
            {
                go[cu][a]=ne[cu][a];
                qu.push(ne[cu][a]);
            }
            else
            {
                if(cu!=0) go[cu][a]=go[bor[cu].link][a];
                else go[cu][a]=0;
            }
        }
        qu.pop();
    }
    int cu=0, q[s.size()];
    for(int a=0; a<s.size(); a++) q[a]=0;
    for(int a=0; a<s.size(); a++)
    {
        cu=go[cu][s[a]-'a'];
        int x=cu;
        while(x!=0)
        {
            if(bor[x].nu!=-1) q[(a+1)-ar[bor[x].nu].size()]+=bor[x].q;
            x=bor[x].link2;
        }
    }
    long long an=0;
    cu=0;
    for(int a=0; a<s.size(); a++)
    {
        cu=go[cu][s[a]-'a'];
        int x=cu, cq=0;
        while(x!=0)
        {
            if(bor[x].nu!=-1) cq+=bor[x].q;
            x=bor[x].link2;
        }
        if(a+1<s.size()) an+=1ll*cq*q[a+1];
    }
    cout<<an;
}