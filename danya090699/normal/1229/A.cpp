#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int mask[n], w[n];
    map <int, int> ma;
    for(int a=0; a<n; a++) cin>>mask[a], ma[mask[a]]++;
    for(int a=0; a<n; a++) cin>>w[a];
    int an=0;
    vector <int> good;
    for(auto it=ma.begin(); it!=ma.end(); it++) if((*it).second>1) good.push_back((*it).first);
    for(int a=0; a<n; a++)
    {
        int ok=0;
        for(int b=0; b<good.size(); b++) if((mask[a]&good[b])==mask[a]) ok=1;
        an+=ok*w[a];
    }
    cout<<an;
}