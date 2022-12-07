#include <bits/stdc++.h>
using namespace std;
struct re
{
    int to, nu;
};
re nel;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, d;
    cin>>n>>k>>d;
    bool us[n], an[n-1];
    vector <re> sv[n];
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<n-1; a++) an[a]=0;
    for(int a=0; a<k; a++)
    {
        int nu;
        cin>>nu;
        nu--;
        us[nu]=1;
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        nel.to=v, nel.nu=a;
        sv[u].push_back(nel);
        nel.to=u, nel.nu=a;
        sv[v].push_back(nel);
    }
    queue <int> qu;
    for(int a=0; a<n; a++) if(us[a]) qu.push(a);
    while(qu.size()!=0)
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int v=qu.front();
            //cout<<v<<" ";
            for(int b=0; b<sv[v].size(); b++)
            {
                int ne=sv[v][b].to, nu=sv[v][b].nu;
                if(us[ne]==0)
                {
                    an[nu]=1;
                    us[ne]=1;
                    qu.push(ne);
                }
            }
            qu.pop();
        }
        //cout<<"\n";
    }
    int qq=0;
    for(int a=0; a<n-1; a++) if(an[a]==0) qq++;
    cout<<qq<<"\n";
    for(int a=0; a<n-1; a++) if(an[a]==0) cout<<a+1<<" ";
}