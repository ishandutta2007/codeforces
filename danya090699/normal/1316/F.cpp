#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, mod=1e9+7;

struct el
{
    int su, q, l, r;
};
el dot[sz*8];
int st[sz], us[sz*2];
vector <pair <int, int> > ar;

void recalc(int nu)
{
    dot[nu].su=(dot[nu*2].su+dot[nu*2+1].su+1ll*dot[nu*2].l*dot[nu*2+1].r)%mod;

    dot[nu].q=dot[nu*2].q+dot[nu*2+1].q;

    dot[nu].l=(dot[nu*2+1].l+1ll*dot[nu*2].l*st[dot[nu*2+1].q])%mod;

    dot[nu].r=(dot[nu*2].r+1ll*dot[nu*2+1].r*st[dot[nu*2].q])%mod;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        if(us[l])
        {
            dot[nu].su=0;
            dot[nu].q=1;
            dot[nu].l=1ll*ar[l].first*st[1]%mod;
            dot[nu].r=dot[nu].l;
        }
        else dot[nu]={0, 0, 0, 0};
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int cha(int nu, int l, int r, int p)
{
    if(l==r)
    {
        if(us[l])
        {
            dot[nu].su=0;
            dot[nu].q=1;
            dot[nu].l=1ll*ar[l].first*st[1]%mod;
            dot[nu].r=dot[nu].l;
        }
        else dot[nu]={0, 0, 0, 0};
    }
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid, p);
        else cha(nu*2+1, mid+1, r, p);
        recalc(nu);
    }
}
int pos(pair <int, int> x)
{
    return lower_bound(ar.begin(), ar.end(), x)-ar.begin();
}

main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    st[0]=1;
    for(int a=1; a<=n; a++) st[a]=1ll*st[a-1]*500000004%mod;
    pair <int, int> sp[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &sp[a].first);
        sp[a].second=a;
        ar.push_back(sp[a]);
    }
    int q;
    cin>>q;
    int qu[q][2];
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &qu[a][0], &qu[a][1]);
        qu[a][0]--;
        ar.push_back({qu[a][1], a+n});
    }
    sort(ar.begin(), ar.end());
    for(int a=0; a<n; a++) us[pos(sp[a])]=1;
    build(1, 0, ar.size()-1);
    printf("%d\n", dot[1].su);
    for(int a=0; a<q; a++)
    {
        int p=pos(sp[qu[a][0]]);
        us[p]=0, cha(1, 0, ar.size()-1, p);
        sp[qu[a][0]]={qu[a][1], a+n};
        p=pos(sp[qu[a][0]]);
        us[p]=1, cha(1, 0, ar.size()-1, p);
        printf("%d\n", dot[1].su);
    }
}