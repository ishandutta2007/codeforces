#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <int> dot[sz*4];
vector <pair <int, int> > sp;
int ar[sz];
void build(int nu, int l, int r)
{
    if(l==r) dot[nu].push_back(ar[l]);
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu].resize(dot[nu*2].size()+dot[nu*2+1].size());
        merge(dot[nu*2].begin(), dot[nu*2].end(), dot[nu*2+1].begin(), dot[nu*2+1].end(), dot[nu].begin());
    }
}
int lg, rg;
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        return dot[nu].end()-upper_bound(dot[nu].begin(), dot[nu].end(), rg);
    }
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int l[n], r[n];
    map <pair <int, int>, int > ma;
    for(int a=0; a<n; a++)
    {
        int m;
        scanf("%d", &m);
        int ar[m][2];
        for(int b=0; b<m; b++) scanf("%d%d", &ar[b][0], &ar[b][1]);
        l[a]=sp.size();
        for(int b=0; b<m; b++)
        {
            int x=ar[b][0]-ar[(b+1)%m][0], y=ar[b][1]-ar[(b+1)%m][1];
            int d=__gcd(abs(x), abs(y));
            x/=d, y/=d;
            sp.push_back({x, y});
            ma[{x, y}]=0;
        }
        r[a]=sp.size();
    }
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=m++;
    int ne[m];
    for(int a=0; a<m; a++) ne[a]=1e9;
    for(int a=sp.size()-1; a>=0; a--)
    {
        ar[a]=ne[ma[sp[a]]], ne[ma[sp[a]]]=a;
    }
    build(1, 0, sp.size()-1);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ll, rr;
        scanf("%d%d", &ll, &rr);
        ll--, rr--;
        lg=l[ll], rg=r[rr]-1;
        printf("%d\n", que(1, 0, sp.size()-1));
    }
}