#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sp[m];
    for(int a=0; a<n; a++)
    {
        int p, c;
        cin>>p>>c;
        sp[p-1].push_back(c);
    }
    for(int a=0; a<m; a++) sort(sp[a].begin(), sp[a].end());
    long long an=1e18;
    for(int a=sp[0].size(); a<=n; a++)
    {
        int lef=a-sp[0].size();
        vector <int> ve;
        long long cu=0;
        for(int b=1; b<m; b++)
        {
            if(sp[b].size()>=a)
            {
                for(int c=0; (c<=sp[b].size()-a and c<sp[b].size()); c++)
                {
                    cu+=sp[b][c], lef--;
                }
                for(int c=sp[b].size()-a+1; c<sp[b].size(); c++) ve.push_back(sp[b][c]);
            }
            else
            {
                for(int c=0; c<sp[b].size(); c++) ve.push_back(sp[b][c]);
            }
        }
        sort(ve.begin(), ve.end());
        for(int b=0; b<lef; b++) cu+=ve[b];
        an=min(an, cu);
    }
    cout<<an;
}