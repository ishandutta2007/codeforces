#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        vector<pair <char, int> > sp[2];
        for(int i=0; i<2; i++)
        {
            string s;
            cin>>s;
            int yk=0;
            while(yk<s.size())
            {
                sp[i].push_back({s[yk], 0});
                while(yk<s.size())
                {
                    if(s[yk]==sp[i].back().first) sp[i].back().second++, yk++;
                    else break;
                }
            }
        }
        bool ok=1;
        if(sp[0].size()!=sp[1].size()) ok=0;
        else
        {
            for(int a=0; a<sp[0].size(); a++)
            {
                if(sp[0][a].first!=sp[1][a].first or sp[0][a].second>sp[1][a].second) ok=0;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}