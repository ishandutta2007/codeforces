//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=75000+10, mod=1e9;
int n, m, ar[sz][6], lg, rg, x;
long long last=0;
vector <int> gr[sz*4];
vector <pair <int, pair <int, int> > > ve[sz*4];
vector <pair <long long, long long> > va[sz*4];
void build(int nu, int l, int r)
{
    if(l==r)
    {
        ve[nu].push_back(make_pair(0, make_pair(l, 0)));
        ve[nu].push_back(make_pair(ar[l][0]+1, make_pair(l, 1)));
        ve[nu].push_back(make_pair(ar[l][1]+1, make_pair(l, 2)));
    }
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        ve[nu].resize(ve[nu*2].size()+ve[nu*2+1].size());
        merge(ve[nu*2].begin(), ve[nu*2].end(), ve[nu*2+1].begin(), ve[nu*2+1].end(), ve[nu].begin());
    }
    int yk=0, pr=0;
    long long su=0, sp=0;
    while(yk<ve[nu].size())
    {
        int cu=ve[nu][yk].first;
        su+=(cu-pr)*sp;
        while(yk<ve[nu].size())
        {
            if(ve[nu][yk].first==cu)
            {
                int nb=ve[nu][yk].second.first, f=ve[nu][yk].second.second;
                int x1=ar[nb][0], x2=ar[nb][1], y1=ar[nb][2], a=ar[nb][3], b=ar[nb][4], y2=ar[nb][5];
                if(f==0) su+=y1;
                if(f==1)
                {
                    su-=y1, su+=a*(x1+1)+b, sp+=a;
                }
                if(f==2)
                {
                    su-=a*(x2+1)+b, su+=y2, sp-=a;
                }
                yk++;
            }
            else break;
        }
        gr[nu].push_back(cu);
        va[nu].push_back(make_pair(su, sp));
        pr=cu;
    }
}
long long que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        int po=upper_bound(gr[nu].begin(), gr[nu].end(), x)-gr[nu].begin()-1;
        return va[nu][po].first+va[nu][po].second*(x-gr[nu][po]);
    }
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++) for(int b=0; b<6; b++) scanf("%d", &ar[a][b]);
    build(1, 0, n-1);
    cin>>m;
    for(int a=0; a<m; a++)
    {
        scanf("%d%d%d", &lg, &rg, &x);
        lg--, rg--, x=(x+last)%mod;
        last=que(1, 0, n-1);
        printf("%lld\n", last);
    }
}