#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin>>k;
    map <int, vector <pair <int, int> > > ma;
    for(int a=0; a<k; a++)
    {
        int q;
        scanf("%d", &q);
        int ar[q], su=0;
        for(int b=0; b<q; b++)
        {
            scanf("%d", &ar[b]), su+=ar[b];
        }
        for(int b=0; b<q; b++)
        {
            ma[su-ar[b]].push_back(make_pair(a+1, b+1));
        }
    }
    bool fo=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        vector <pair <int, int> > &ve=(*it).second;
        sort(ve.begin(), ve.end());
        for(int a=1; a<ve.size(); a++)
        {
            if(ve[a].first!=ve[a-1].first)
            {
                cout<<"YES\n";
                cout<<ve[a].first<<" "<<ve[a].second<<"\n";
                cout<<ve[a-1].first<<" "<<ve[a-1].second;
                fo=1;
                break;
            }
        }
        if(fo) break;
    }
    if(fo==0) cout<<"NO";
}