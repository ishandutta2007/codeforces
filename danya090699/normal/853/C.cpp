//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int ar[sz], x, lg, rg;
vector <int> dot[sz*4];
void build(int nu, int l, int r)
{
    if(l==r) dot[nu].push_back(ar[l]);
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu].resize(dot[nu*2].size()+dot[nu*2+1].size());
        merge(dot[nu*2].begin(), dot[nu*2].end(), dot[nu*2+1].begin(), dot[nu*2+1].end(), dot[nu].begin());
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        int p=lower_bound(dot[nu].begin(), dot[nu].end(), x)-dot[nu].begin();
        return p;
    }
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
long long qq(int a)
{
    if(a==0) return 0;
    else return (1ll*a*(a-1))/2;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    long long all=qq(n);
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ar[a]--;
    }
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int l, d, r, u;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        l--, d--, r--, u--;
        long long an=qq(l)+qq(n-(r+1))+qq(d)+qq(n-(u+1));
        //if(a==0) cout<<an;
        if(l>0)
        {
            lg=0, rg=l-1, x=d;
            int q2=que(1, 0, n-1);
            an-=qq(q2);
            x=u+1;
            q2=que(1, 0, n-1);
            an-=qq(l-q2);
        }
        if(r<n-1)
        {
            lg=r+1, rg=n-1, x=d;
            int q2=que(1, 0, n-1);
            an-=qq(q2);
            x=u+1;
            q2=que(1, 0, n-1);
            an-=qq((n-(r+1))-q2);
        }
        printf("%lld\n", all-an);
    }
}