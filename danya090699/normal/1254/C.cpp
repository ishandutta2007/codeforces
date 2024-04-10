#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    vector <pair <int, int> > sp[2];
    vector <int> an;
    for(int a=3; a<=n; a++)
    {
        cout<<"1 1 2 "<<a<<"\n";
        int si, s;
        cin>>s;
        cout<<"2 1 2 "<<a<<"\n";
        cin>>si;
        if(si==-1) sp[0].push_back({s, a});
        else sp[1].push_back({s, a});
    }
    for(int i=0; i<2; i++)
    {
        an.push_back(i+1);
        sort(sp[i].begin(), sp[i].end());
        vector <int> ve;
        for(int a=0; a+1<sp[i].size(); a++)
        {
            cout<<"2 "<<i+1<<" "<<sp[i].back().second<<" "<<sp[i][a].second<<"\n";
            int si;
            cin>>si;
            if(si==-1) an.push_back(sp[i][a].second);
            else ve.push_back(sp[i][a].second);
        }
        if(sp[i].size()) an.push_back(sp[i].back().second);
        while(ve.size())
        {
            an.push_back(ve.back());
            ve.pop_back();
        }
    }
    cout<<"0 ";
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
    cout<<"\n";
}