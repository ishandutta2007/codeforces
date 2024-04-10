#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=4e5+10;
pair <int, int> wo[sz], ca[sz];
int m, n, add[sz], add2=0, su=0, be=1e18, an, re[sz];
int di(int x, int y)
{
    if(x>y) swap(x, y);
    return min(y-x, x+m-y);
}
void f(int l, int r, int wnu)
{
    int lg=lower_bound(ca, ca+n*2, make_pair(l+1, 0ll))-ca;
    int rg=lower_bound(ca, ca+n*2, make_pair(r, 0ll))-ca-1;
    while(lg<=rg)
    {
        int cnu=lg%n, st=(wnu-cnu+n)%n;
        int d=di(wo[(wnu+1)%n].first, ca[cnu].first)-di(wo[wnu].first, ca[cnu].first);
        add[st]+=d, add[st+1]-=d;
        lg++;
    }
}
void f2(int l, int r, int wnu, int va)
{
    int lg=lower_bound(ca, ca+n*2, make_pair(l, 0ll))-ca;
    int rg=lower_bound(ca, ca+n*2, make_pair(r+1, 0ll))-ca-1;
    if(lg<=rg)
    {
        swap(lg, rg);
        lg=(wnu-(lg%n)+n)%n, rg=(wnu-(rg%n)+n)%n;

        if(lg<=rg) add[lg]+=va, add[rg+1]-=va;
        else
        {
            add[0]+=va, add[rg+1]-=va;
            add[lg]+=va;
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>m>>n;
    m*=2;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &wo[a].first), wo[a].first=(wo[a].first-1)*2, wo[a].second=a;
        wo[a+n].first=wo[a].first+m, wo[a+n].second=a;
    }
    sort(wo, wo+n*2);
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ca[a].first), ca[a].first=(ca[a].first-1)*2, ca[a].second=a;
        ca[a+n].first=ca[a].first+m, ca[a+n].second=a;
    }
    sort(ca, ca+n*2);
    for(int a=0; a<n; a++)
    {
        su+=di(wo[a].first, ca[a].first);
        int l=wo[a].first, r=wo[a+1].first;
        if(l!=r)
        {
            if(r-l>m/2)
            {
                for(int b=0; b<n; b++)
                {
                    int st=a-b, d=di(ca[b].first, r%m)-di(ca[b].first, l);
                    if(st<0) st+=n;
                    add[st]+=d, add[st+1]-=d;
                }
            }
            else
            {
                f(l, r, a), f(l+m/2, r+m/2, a);
                f2(r, l+m/2, a, -(r-l)), f2(r+m/2, l+m, a, r-l);
            }
        }
    }

    for(int a=0; a<n; a++)
    {
        if(su<be) be=su, an=a;
        add2+=add[a], su+=add2;
    }
    for(int a=0; a<n; a++)
    {
        re[wo[(a+an)%n].second]=ca[a].second+1;
    }
    cout<<be/2<<"\n";
    for(int a=0; a<n; a++) printf("%lld ", re[a]);
}