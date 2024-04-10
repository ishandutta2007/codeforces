#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, inf=1e9;
int bl;
vector <pair <int, int> > sp[sz];
vector <int> q0[sz], qq[sz];
vector <int> add[sz];
int n, k, q, bq[sz], an=0, tbq=0;
int ar[2][sz], bv[sz];
void recalc(int i, int l, int r)
{
    an-=q0[i][l];
    int p=upper_bound(sp[i].begin()+l, sp[i].begin()+r, make_pair(add[i][l], -inf))-sp[i].begin();
    if(p!=r and sp[i][p].first==add[i][l]) q0[i][l]=qq[i][p];
    else q0[i][l]=0;
    an+=q0[i][l];
    if(r==sp[i].size() and i!=n%k)
    {
        tbq-=bq[i];
        if(p!=r and sp[i][p].first==add[i][l] and sp[i][p].first==bv[i]) bq[i]=0;
        else bq[i]=1;
        tbq+=bq[i];
    }
}
void build(int i, int l, int r)
{
    for(int a=l; a<r; a++) sp[i][a].first^=add[i][l];
    add[i][l]=0;
    sort(sp[i].begin()+l, sp[i].begin()+r);
    int yk=l;
    while(yk<r)
    {
        int st=yk;
        qq[i][st]=0;
        while(yk<r)
        {
            if(sp[i][yk].first==sp[i][st].first) qq[i][st]++, yk++;
            else break;
        }
    }
    if(r==sp[i].size() and i!=n%k)
    {
        for(int a=l; a<r; a++) if(sp[i][a].second==r-1) bv[i]=sp[i][a].first;
    }
    recalc(i, l, r);
}
void cha(int i, int l, int x)
{
    int n=sp[i].size();
    for(int lg=0; lg<sp[i].size(); lg+=bl)
    {
        int rg=min(lg+bl, int(sp[i].size()));
        if(rg>l)
        {
            if(lg>=l)
            {
                add[i][lg]^=x;
                recalc(i, lg, rg);
            }
            else
            {
                for(int a=lg; a<rg; a++)
                {
                    if(sp[i][a].second>=l) sp[i][a].first^=x;
                }
                build(i, lg, rg);
            }
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k>>q;
    bl=ceil(sqrt(n/k));
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) scanf("%d", &ar[i][a]);
    }
    if(k==1)
    {
        int nq=0;
        for(int a=0; a<n; a++) if(ar[0][a]==ar[1][a]) nq++;
        printf("%d\n", n-nq);
        for(int a=0; a<q; a++)
        {
            char s[2];
            scanf("%s", s);
            int ty=s[0]-'a', p;
            int x;
            scanf("%d%d", &p, &x);
            p--;
            if(ar[0][p]==ar[1][p]) nq--;
            ar[ty][p]=x;
            if(ar[0][p]==ar[1][p]) nq++;
            printf("%d\n", n-nq);
        }
    }
    else
    {
        int su=0, ar2[n];
        for(int a=0; a<n; a++)
        {
            if(a-k>=0) su^=ar2[a-k];
            ar2[a]=ar[0][a]^ar[1][a]^su;
            su^=ar2[a];
            sp[a%k].push_back({ar2[a], a/k});
        }
        for(int a=0; a<k; a++)
        {
            add[a].resize(sp[a].size(), 0);
            q0[a].resize(sp[a].size(), 0);
            qq[a].resize(sp[a].size(), 0);
            for(int lg=0; lg<sp[a].size(); lg+=bl) build(a, lg, min(lg+bl, int(sp[a].size())));
        }
        if(tbq==0) printf("%d\n", n-an);
        else printf("-1\n");
        for(int a=0; a<q; a++)
        {
            char s[2];
            scanf("%s", s);
            int ty=s[0]-'a', p;
            int x;
            scanf("%d%d", &p, &x);
            p--;
            int d=ar[ty][p]^x;
            cha(p%k, p/k, d);
            if(p+1<n) cha((p+1)%k, (p+1)/k, d);
            if(tbq==0) printf("%d\n", n-an);
            else printf("-1\n");
            ar[ty][p]=x;
        }
    }
}