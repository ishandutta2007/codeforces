#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    vector <pair <int, int> > an;
    for(int a=n-1; a>=0; a--)
    {
        vector <pair <int, int> > sp;
        for(int b=0; b<a; b++) if(ar[b]>ar[a]) sp.push_back({ar[b], b});
        sort(sp.begin(), sp.end());
        for(int b=0; b<sp.size(); b++)
        {
            an.push_back({sp[b].second+1, a+1});
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
}