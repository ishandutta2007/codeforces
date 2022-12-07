#include <bits/stdc++.h>
using namespace std;
int n, k, *ba, *noba;
vector <int*> *sv;
bool comp(int *a, int *b){return a[0]>b[0];}
void dfs(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a][0];
        if(ne!=pr) dfs(ne, v);
    }
    noba[v]=0;
    int lef=k-1;
    vector <int> ar;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a][0], pri=sv[v][a][1];
        if(ne!=pr) ar.push_back(noba[ne]+pri);
    }
    sort(ar.begin(), ar.end());
    while(lef>0 and ar.size()>0)
    {
        noba[v]+=ar.back();
        ar.pop_back();
        lef--;
    }
    ba[v]=0;
    vector <int*> be;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a][0], pri=sv[v][a][1];
        if(ne!=pr)
        {
            int *nel=new int[2];
            be.push_back(nel);
            be.back()[0]=noba[ne]+pri;
            be.back()[1]=ba[ne]+pri;
        }
    }
    sort(be.begin(), be.end(), comp);
    int cu=0, m=be.size();
    for(int a=0; a<min(m, k); a++) cu+=be[a][0];
    for(int a=0; a<be.size(); a++)
    {
        if(a<k) ba[v]=max(ba[v], cu-be[a][0]+be[a][1]);
        else ba[v]=max(ba[v], cu-be[k-1][0]+be[a][1]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    sv=new vector <int*>[n], ba=new int[n], noba=new int[n];
    for(int a=0; a<n-1; a++)
    {
        int u, v, pr;
        scanf("%d%d%d", &u, &v, &pr);
        sv[u].push_back(new int[2]);
        sv[u].back()[0]=v, sv[u].back()[1]=pr;
        sv[v].push_back(new int[2]);
        sv[v].back()[0]=u, sv[v].back()[1]=pr;
    }
    dfs(0, -1);
    cout<<ba[0];
}