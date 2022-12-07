#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int h[sz];
void dfs(int v, int he)
{
    h[he]^=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne, he+1);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        int v;
        cin>>v;
        v--;
        sv[v].push_back(a);
    }
    dfs(0, 0);
    for(int a=0; a<n; a++) an+=h[a];
    cout<<an;
}