#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    vector <int> sp[2], an;
    for(int a=0; a<4; a++)
    {
        int q;
        cin>>q;
        while(q--) sp[a&1].push_back(a);
    }
    int i=(sp[1].size()>=sp[0].size());
    while(sp[i].size())
    {
        an.push_back(sp[i].back());
        sp[i].pop_back();
        i^=1;
    }
    if(sp[0].size() or sp[1].size())
    {
        cout<<"NO";
        return 0;
    }
    for(int a=1; a<an.size(); a++)
    {
        if(abs(an[a]-an[a-1])!=1)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}