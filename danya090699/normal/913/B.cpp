#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ok=1;
    cin>>n;
    vector <int> sv[n];
    for(int a=1; a<n; a++)
    {
        int u;
        cin>>u;
        sv[u-1].push_back(a);
    }
    for(int a=0; a<n; a++)
    {
        if(sv[a].size())
        {
            int q=0;
            for(int b=0; b<sv[a].size(); b++)
            {
                int v=sv[a][b];
                if(sv[v].size()==0) q++;
            }
            if(q<3) ok=0;
        }
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}