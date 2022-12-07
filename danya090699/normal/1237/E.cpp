#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <pair <int, int> > sp;
void dfs(int h, int va)
{
    if(h) dfs(h-1, va^1);
    sp.push_back({va, h});
    if(h) dfs(h-1, va);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, h=0, m=1, an=0;
    cin>>n;
    while(m*2+1<=n) m=m*2+1, h++;
    //cout<<m<<" "<<h<<"\n";
    for(int i=0; i<2; i++)
    {
        dfs(h, i);
        //for(int a=0; a<sp.size(); a++) cout<<sp[a].first<<" "<<sp[a].second<<"\n";
        reverse(sp.begin(), sp.end());
        int ok=1;
        for(int a=0; a<n; a++)
        {
            if(sp.size())
            {
                if(sp.back().first==a%2)
                {
                    //cout<<a<<" ";
                    sp.pop_back();
                }
                else
                {
                    if(sp.back().first==a%2 or sp.back().second)
                    {
                        ok=0;
                    }
                }
            }
            else ok=0;
        }
        if(sp.size())
        {
            ok=0;
            sp.clear();
        }
        an+=ok;
    }
    cout<<an;
}