//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=110;
vector <pair<int, int> > sv[sz];
void dfs(int v, int pr, double ti)
{
    int q=sv[v].size();
    for(int a=0; a<q; a++)
    {
        int ne=sv[v][a].first, nu=sv[v][a].second;
        if(ne!=pr)
        {
            cout<<1<<" "<<nu<<" ";
            ti+=(2.0/q);
            if(ti>2) ti-=2;
            if(ti<1)
            {
                cout<<ne+1<<" "<<v+1<<" "<<1-ti<<"\n";
                dfs(ne, v, 1+ti);
            }
            else
            {
                cout<<v+1<<" "<<ne+1<<" "<<2-ti<<"\n";
                dfs(ne, v, ti-1);
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cout.precision(10);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(make_pair(v, a+1));
        sv[v].push_back(make_pair(u, a+1));
    }
    cout<<n-1<<"\n";
    dfs(0, -1, 0);
}