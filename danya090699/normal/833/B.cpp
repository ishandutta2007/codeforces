//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=35e3+10, sz2=60, inf=1e9;
struct el
{
    int ma=0, add=0;
};
el dot[sz2][sz*4];
int cu, lg, rg, add;
void push(int nu)
{
    dot[cu][nu*2].add+=dot[cu][nu].add;
    dot[cu][nu*2+1].add+=dot[cu][nu].add;
    dot[cu][nu].add=0;
}
void recalc(int nu)
{
    dot[cu][nu].ma=max(dot[cu][nu*2].ma+dot[cu][nu*2].add, dot[cu][nu*2+1].ma+dot[cu][nu*2+1].add);
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[cu][nu].add+=add;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[cu][nu].ma+dot[cu][nu].add;
    else if(l>rg or r<lg) return -inf;
    else
    {
        int mid=(l+r)/2;
        push(nu);
        int can=max(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
        recalc(nu);
        return can;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    vector <int> pi[n];
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar[a]--;
    }
    for(int a=1; a<k; a++)
    {
        cu=a, lg=0, rg=0, add=-inf;
        cha(1, 0, n);
    }
    for(int a=1; a<=n; a++)
    {
        int cur=ar[a-1], pr=-1;
        if(pi[cur].size()>0) pr=pi[cur].back();
        for(int b=0; b<k; b++)
        {
            cu=b, lg=pr+1, rg=a-1, add=1;
            cha(1, 0, n);
        }
        for(int b=1; b<=k; b++)
        {
            cu=b-1, lg=0, rg=a-1;
            int an=que(1, 0, n);
            if(an<0) an=-inf;
            cu=b, lg=a, rg=a, add=an;
            cha(1, 0, n);
            if(a==n and b==k) cout<<an;
        }
        pi[cur].push_back(a-1);
    }
}