//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <pair<int, int> > ve[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, xx, an, inf=2e9+10;
    an=inf;
    cin>>n>>xx;
    int pu[n][3];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<3; b++) scanf("%d", &pu[a][b]);
        ve[pu[a][1]-pu[a][0]+1].push_back(make_pair(pu[a][0], pu[a][2]));
    }
    for(int a=0; a<sz; a++)
    {
        sort(ve[a].begin(), ve[a].end());
        int m=ve[a].size();
        for(int b=m-2; b>=0; b--) ve[a][b].second=min(ve[a][b].second, ve[a][b+1].second);
    }
    for(int a=0; a<n; a++)
    {
        int l=pu[a][0], r=pu[a][1], va=pu[a][2], se;
        se=xx-(r-l+1);
        if(se>0)
        {
            int x=lower_bound(ve[se].begin(), ve[se].end(), make_pair(r+1, 0))-ve[se].begin();
            if(x<ve[se].size()) an=min(an, va+ve[se][x].second);
        }
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}