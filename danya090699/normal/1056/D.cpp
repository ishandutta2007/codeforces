#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5+10;
vector <int> sv[sz];
int ar[sz];
void dfs(int v)
{
    ar[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), ar[v]+=ar[ne];
    }
    if(ar[v]==0) ar[v]=1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%d", &pr);
        pr--;
        sv[pr].push_back(a);
    }
    dfs(0);
    sort(ar, ar+n);
    for(int a=0; a<n; a++) printf("%d ", ar[a]);
}