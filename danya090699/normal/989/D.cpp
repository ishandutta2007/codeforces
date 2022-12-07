#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, le, wm;
    cin>>n>>le>>wm;
    vector <int> sp[2];
    for(int a=0; a<n; a++)
    {
        int x, w;
        scanf("%d%d", &x, &w);
        if(w==1) sp[0].push_back(x);
        else sp[1].push_back(x);
    }
    sort(sp[0].begin(), sp[0].end());
    sort(sp[1].begin(), sp[1].end());
    long long an=0;
    for(int a=0; a<sp[0].size(); a++)
    {
        int x=sp[0][a]+le;
        int l=-1, r=sp[1].size();
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            int x2=sp[1][mid];
            if(x2<x) l=mid;
            else
            {
                int t=x2-x+le*2, d=abs(x+x2);
                if((1ll*t*wm)>d) r=mid;
                else l=mid;
            }
        }
        an+=int(sp[1].size())-(l+1);
    }
    cout<<an;
}