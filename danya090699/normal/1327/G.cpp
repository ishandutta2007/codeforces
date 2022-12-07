#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
int q=1, ne[sz][14], pr[sz], prsy[sz], go[sz][14], link[sz], w[sz];
long long dp[sz][1<<14], dp2[sz][1<<14], inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin>>k;
    for(int a=0; a<14; a++) ne[0][a]=-1;
    for(int a=0; a<k; a++)
    {
        string str;
        cin>>str;
        int va, s=0;
        cin>>va;
        for(int b=0; b<str.size(); b++)
        {
            int sy=str[b]-'a';
            if(ne[s][sy]==-1)
            {
                ne[s][sy]=q, pr[q]=s, prsy[q]=sy;
                for(int c=0; c<14; c++) ne[q][c]=-1;
                q++;
            }
            s=ne[s][sy];
        }
        w[s]+=va;
    }
    queue <int> qu;
    qu.push(0);
    while(qu.size())
    {
        int v=qu.front();
        if(pr[v]) link[v]=go[link[pr[v]]][prsy[v]];
        w[v]+=w[link[v]];
        for(int a=0; a<14; a++)
        {
            if(ne[v][a]==-1) go[v][a]=go[link[v]][a];
            else
            {
                go[v][a]=ne[v][a];
                qu.push(ne[v][a]);
            }
        }
        qu.pop();
    }
    string s;
    cin>>s;
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<(1<<14); b++) dp[a][b]=-inf, dp2[a][b]=-inf;
    }
    dp[0][0]=0;
    int yk=0;
    while(yk<s.size())
    {
        if(s[yk]=='?')
        {
            for(int a=0; a<q; a++)
            {
                for(int mask=0; mask<(1<<14); mask++)
                {
                    if(dp[a][mask]!=-inf)
                    {
                        for(int i=0; i<14; i++)
                        {
                            if((mask&(1<<i))==0)
                            {
                                int to=go[a][i];
                                dp2[to][mask+(1<<i)]=max(dp2[to][mask+(1<<i)], dp[a][mask]+w[to]);
                            }
                        }
                    }
                }
            }
            yk++;
        }
        else
        {
            int l=yk;
            while(yk<s.size() and s[yk]!='?') yk++;
            for(int a=0; a<q; a++)
            {
                int v=a;
                long long add=0;
                for(int b=l; b<yk; b++)
                {
                    v=go[v][s[b]-'a'];
                    add+=w[v];
                }
                for(int mask=0; mask<(1<<14); mask++)
                {
                    dp2[v][mask]=max(dp2[v][mask], dp[a][mask]+add);
                }
            }
        }
        for(int a=0; a<q; a++)
        {
            for(int b=0; b<(1<<14); b++) dp[a][b]=dp2[a][b], dp2[a][b]=-inf;
        }
    }
    long long an=-inf;
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<(1<<14); b++) an=max(an, dp[a][b]);
    }
    cout<<an;
}