#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, q, por, a[200003], u[200003], k[200003], poverpor[200003], poporver[200003], kolpod[200003];
vector <int> m[200003];
void dfs(int v)
{
    poverpor[v]=por;
    poporver[por]=v;
    por++;
    for(int i=0;i<m[v].size();i++)
        dfs(m[v][i]);
    kolpod[v]=por-poverpor[v];
}

int main()
{
    cin >> n >> q;
    for(int i=1;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
        m[a[i]].push_back(i);
    }
    for(int i=0;i<q;i++)
    {
        cin >> u[i] >> k[i];
        u[i]--;
    }
    for(int i=0;i<n;i++)
        sort(m[i].begin(), m[i].end());
    por=1;
    dfs(0);
    for(int i=0;i<q;i++)
    {
        if(kolpod[u[i]]<k[i])
            cout << -1 << endl;
        else cout << poporver[poverpor[u[i]]+k[i]-1]+1 << endl;
    }
    return 0;
}