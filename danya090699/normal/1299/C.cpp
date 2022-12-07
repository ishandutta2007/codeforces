#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector <pair <int, int> > sp;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        sp.push_back({x, 1});
        while(sp.size()>1)
        {
            double v1=(1.0*sp.back().first)/sp.back().second;
            double v2=(1.0*sp[sp.size()-2].first)/sp[sp.size()-2].second;
            if(v1<=v2)
            {
                sp[sp.size()-2].first+=sp.back().first;
                sp[sp.size()-2].second+=sp.back().second;
                sp.pop_back();
            }
            else break;
        }
    }
    for(int a=0; a<sp.size(); a++)
    {
        double x=(1.0*sp[a].first)/sp[a].second;
        for(int b=0; b<sp[a].second; b++) printf("%.10f\n", x);
    }
}