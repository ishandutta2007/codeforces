#include <bits/stdc++.h>
using namespace std;
struct el
{
    double s, l, r, va;
    int len;
};
vector <el> sp;
bool comp(int a, int b)
{
    if(sp[a].s!=sp[b].s) return sp[a].s>sp[b].s;
    else return a<b;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, L, pr=0;
    cin>>n>>L;
    for(int a=0; a<n; a++)
    {
        int l, r;
        double s;
        scanf("%d%d%lf", &l, &r, &s);

        if(l>pr) sp.push_back({0, 0, 0, 0, l-pr});
        sp.push_back({s, 0, 0, 0, r-l});
        pr=r;
    }
    if(pr<L) sp.push_back({0, 0, 0, 0, L-pr});

    set <int, bool(*)(int, int)> se(&comp);

    for(int a=0; a<sp.size(); a++)
    {
        el &cu=sp[a];
        if(cu.s!=0) cu.l=-(cu.len/cu.s);
        cu.r=cu.len/(cu.s+2);

        while(se.size() and sp[*se.begin()].s>cu.s)
        {
            el &be=sp[*se.begin()];
            if(cu.r-cu.va>be.va-be.l)
            {
                cu.va+=be.va-be.l, be.va=be.l;
                se.erase(se.begin());
            }
            else
            {
                be.va-=cu.r-cu.va, cu.va=cu.r;
                break;
            }
        }
        se.insert(a);
    }
    double an=0;
    for(int a=0; a<sp.size(); a++) an+=(sp[a].len-sp[a].va)/(1+sp[a].s);
    cout<<fixed<<setprecision(15)<<an;
}