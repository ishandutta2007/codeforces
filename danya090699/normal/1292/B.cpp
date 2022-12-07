#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e16+10;
main()
{
    //freopen("input.txt", "r", stdin);
    vector <pair <int, int> > sp(1);
    int ax, ay, bx, by;
    cin>>sp[0].first>>sp[0].second>>ax>>ay>>bx>>by;
    int xs, ys, t, an=0;
    cin>>xs>>ys>>t;
    while(1)
    {
        int x=sp.back().first*ax+bx, y=sp.back().second*ay+by;
        //cout<<x<<" "<<y<<"\n";
        if(x<inf and y<inf) sp.push_back({x, y});
        else break;
    }
    for(int a=0; a<sp.size(); a++)
    {
        for(int b=0; b<=a; b++)
        {
            int cu=abs(xs-sp[a].first)+abs(ys-sp[a].second)+(sp[a].first-sp[b].first)+(sp[a].second-sp[b].second);
            if(cu<=t)
            {
                an=max(an, a-b+1);
                for(int c=a+1; c<sp.size(); c++)
                {
                    int cu2=cu+(sp[c].first-sp[b].first)+(sp[c].second-sp[b].second);
                    if(cu2<=t) an=max(an, c-b+1);
                }
            }
        }
    }
    cout<<an;
}