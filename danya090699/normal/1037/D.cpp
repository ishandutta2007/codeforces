#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int pr[sz], h[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            h[ne]=h[v]+1, pr[ne]=v, dfs(ne);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    h[0]=0, pr[0]=0, dfs(0);
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ar[a]--;
    }
    int yk=0, ok=1;
    vector <int> sta;
    for(int le=0; le<n; le++)
    {

        if(yk<n)
        {
            if(h[ar[yk]]==le)
            {
                int st=yk;
                while(yk<n)
                {
                    int v=ar[yk];
                    if(h[v]==le)
                    {
                        if(le!=0)
                        {
                            bool fo=0;
                            while(sta.size())
                            {
                                if(sta.back()==pr[v])
                                {
                                    fo=1;
                                    break;
                                }
                                else sta.pop_back();
                            }
                            if(fo==0) ok=0;
                        }
                        yk++;
                    }
                    else break;
                }
                sta.clear();
                for(int a=yk-1; a>=st; a--) sta.push_back(ar[a]);

                if(ok==0) break;
            }
            else
            {
                if(h[ar[yk]]<le)
                {
                    ok=0;
                    break;
                }
            }
        }
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}