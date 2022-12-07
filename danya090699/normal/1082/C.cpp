#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    vector <int> sp[m];
    for(int a=0; a<n; a++)
    {
        int ty, va;
        scanf("%d%d", &ty, &va);
        ty--;
        sp[ty].push_back(va);
    }
    set <int> se;
    for(int a=0; a<m; a++)
    {
        sort(sp[a].begin(), sp[a].end(), greater <int>());
        se.insert(a);
        for(int b=1; b<sp[a].size(); b++) sp[a][b]+=sp[a][b-1];
    }
    for(int q=1; se.size(); q++)
    {
        int cu=0;
        vector <int> del;
        for(auto it=se.begin(); it!=se.end(); it++)
        {
            int i=(*it);
            if(q>sp[i].size()) del.push_back(i);
            else if(sp[i][q-1]<0) del.push_back(i);
            else cu+=sp[i][q-1];
        }
        an=max(an, cu);
        for(int a=0; a<del.size(); a++) se.erase(del[a]);
    }
    cout<<an;
}