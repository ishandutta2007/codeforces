#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int pr[sz], chq[sz], rnu[sz], re[sz][26], dp[sz][26], su[sz], h[sz], bad=0, bad_tree=0;
char sy[sz];
vector <int> sv[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=1; a<n; a++)
    {
        scanf("%d%s", &pr[a], sy+a);
        pr[a]--, chq[pr[a]]++;
        rnu[a]=a;
    }
    for(int a=n-1; a>=0; a--)
    {
        if(rnu[a]==a)
        {
            for(int b=0; b<sv[a].size(); b++)
            {
                int ne=sv[a][b];
                for(int i=0; i<26; i++) dp[a][i]=max(dp[a][i], dp[ne][i]+re[ne][i]);
            }
            for(int i=0; i<26; i++) su[a]+=dp[a][i];
            if(su[a]>h[a]) bad++;

            if(a)
            {
                int v=a, ch=h[a];
                while(v==a or (chq[v]<2 and v!=0))
                {
                    rnu[v]=a, ch++;
                    if(sy[v]!='?') re[a][sy[v]-'a']++;
                    v=pr[v];
                }
                if(sv[v].size()==0) h[v]=ch;
                sv[v].push_back(a), pr[a]=v;
                if(h[v]!=ch) bad_tree=1;
            }
        }
    }
    for(int a=0; a<q; a++)
    {
        if(bad_tree) printf("Fou\n");
        else
        {
            int v;
            char sym[2];
            scanf("%d%s", &v, sym);
            v--;
            vector <int> sp;
            if(sy[v]!='?') re[rnu[v]][sy[v]-'a']--, sp.push_back(sy[v]-'a');
            if(sym[0]!='?') re[rnu[v]][sym[0]-'a']++, sp.push_back(sym[0]-'a');

            sy[v]=sym[0], v=rnu[v];

            while(v!=0)
            {
                v=pr[v];
                for(int i=0; i<sp.size(); i++)
                {
                    int sy=sp[i];
                    if(su[v]>h[v]) bad--;
                    su[v]-=dp[v][sy], dp[v][sy]=0;
                    for(int b=0; b<sv[v].size(); b++)
                    {
                        int ne=sv[v][b];
                        dp[v][sy]=max(dp[v][sy], dp[ne][sy]+re[ne][sy]);
                    }
                    su[v]+=dp[v][sy];
                    if(su[v]>h[v]) bad++;
                }
            }
            if(bad) printf("Fou\n");
            else
            {
                int an=0;
                for(int i=0; i<26; i++) an+=(i+1)*(dp[0][i]+(h[0]-su[0]));
                printf("Shi %d\n", an);
            }
        }
    }
}