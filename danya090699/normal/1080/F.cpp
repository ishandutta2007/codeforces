#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9+10;
vector <pair <int, int> > dot[sz*4];
map <int, int> ot[sz];
void build(int nu, int l, int r)
{
    if(l==r)
    {
        for(auto it=ot[l].begin(); it!=ot[l].end(); it++) dot[nu].push_back({(*it).first, (*it).second});
        dot[nu].push_back({inf, inf});
        for(int a=int(dot[nu].size())-2; a>=0; a--) dot[nu][a].second=min(dot[nu][a].second, dot[nu][a+1].second);
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        int ykl=0, ykr=0;
        while(ykl<dot[nu*2].size())
        {
            int rg=min(dot[nu*2][ykl].first, dot[nu*2+1][ykr].first);
            int va=max(dot[nu*2][ykl].second, dot[nu*2+1][ykr].second);
            dot[nu].push_back({rg, va});
            if(rg==dot[nu*2][ykl].first) ykl++;
            if(rg==dot[nu*2+1][ykr].first) ykr++;
        }
    }
}
int lg, rg, x, y;
bool que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        int p=upper_bound(dot[nu].begin(), dot[nu].end(), make_pair(x, -1))-dot[nu].begin();
        return (dot[nu][p].second<=y);
    }
    else if(l>rg or r<lg) return 1;
    else
    {
        int mid=(l+r)>>1;
        return (que(nu*2, l, mid)&que(nu*2+1, mid+1, r));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    for(int a=0; a<k; a++)
    {
        int l, r, p;
        scanf("%d%d%d", &l, &r, &p);
        p--;
        if(ot[p].find(l)==ot[p].end()) ot[p][l]=r;
        else ot[p][l]=min(ot[p][l], r);
    }
    build(1, 0, n-1);
    for(int a=0; a<m; a++)
    {
        scanf("%d%d%d%d", &lg, &rg, &x, &y);
        lg--, rg--;
        bool an=que(1, 0, n-1);
        if(an) printf("yes\n");
        else printf("no\n");
        fflush(stdout);
    }
}