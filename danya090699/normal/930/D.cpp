#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int mi[sz*4], ma[sz*4], prefmi[sz*4], prefma[sz*4];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<sz*4; a++)
    {
        mi[a]=inf, ma[a]=-inf;
    }
    for(int a=0; a<n; a++)
    {
        int x, y;
        cin>>x>>y;
        x+=sz, y+=sz;
        mi[x+y]=min(mi[x+y], x-y);
        ma[x+y]=max(ma[x+y], x-y);
    }
    prefmi[0]=mi[0], prefma[0]=ma[0], prefmi[1]=mi[1], prefma[1]=ma[1];
    for(int a=2; a<sz*4; a++)
    {
        prefmi[a]=min(prefmi[a-2], mi[a]);
        prefma[a]=max(prefma[a-2], ma[a]);
    }
    int mi1=inf, ma1=-inf, mi2=inf, ma2=-inf;
    long long an=0;
    for(int a=sz*4-1; a>0; a--)
    {
        int l, r;
        if(a&1)
        {
            l=max(mi1, prefmi[a-1]), r=min(ma1, prefma[a-1]);
            mi2=min(mi2, mi[a]), ma2=max(ma2, ma[a]);
        }
        else
        {
            l=max(mi2, prefmi[a-1]), r=min(ma2, prefma[a-1]);
            mi1=min(mi1, mi[a]), ma1=max(ma1, ma[a]);
        }
        if(l<r) an+=(r-l)/2;
    }
    cout<<an;
}