#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
int fen[sz*2];
vector <pair <int, int> > ve[sz*2], go[sz*2];
void cha(int p, int va)
{
    while(p<sz*2)
    {
        fen[p]+=va, p=p|(p+1);
    }
}
int que(int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[p], p=(p&(p+1))-1;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int xl, yl, xr, yr;
        scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
        if(xl>xr) swap(xl, xr);
        if(yl>yr) swap(yl, yr);
        xl+=sz, xr+=sz, yl+=sz, yr+=sz;
        if(xl==xr) ve[xl].push_back({yl, yr});
        else go[xr].push_back({xl, yl});
    }
    long long an=0;
    for(int a=0; a<sz*2; a++)
    {
        for(int b=0; b<ve[a].size(); b++)
        {
            int ly=ve[a][b].first, ry=ve[a][b].second;
            for(int c=a; c<sz*2; c++)
            {
                for(int d=0; d<go[c].size(); d++)
                {
                    int lx=go[c][d].first, y=go[c][d].second;
                    if(lx<=a) cha(y, 1);
                }
            }
            for(int c=a+1; c<sz*2; c++)
            {
                for(int d=0; d<go[c-1].size(); d++)
                {
                    int lx=go[c-1][d].first, y=go[c-1][d].second;
                    if(lx<=a) cha(y, -1);
                }
                for(int d=0; d<ve[c].size(); d++)
                {
                    int ly2=ve[c][d].first, ry2=ve[c][d].second;
                    int ll=max(ly, ly2), rr=min(ry, ry2);
                    if(ll<rr)
                    {
                        int q=que(rr)-que(ll-1);
                        //cout<<q<<"\n";
                        if(q) an+=q*(q-1)/2;
                    }
                }
            }
        }
    }
    cout<<an;
}