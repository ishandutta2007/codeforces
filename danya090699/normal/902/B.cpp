#include <bits/stdc++.h>
using namespace std;
const int sz=1e4+10;
vector <int> sv[sz];
int ty[sz], an=0;
void dfs(int v, int c)
{
    if(ty[v]!=c) an++;
    for(int a=0; a<sv[v].size(); a++) dfs(sv[v][a], ty[v]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        int v;
        cin>>v;
        sv[v-1].push_back(a);
    }
    for(int a=0; a<n; a++) cin>>ty[a];
    dfs(0, -1);
    cout<<an;
}