#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10, sz=2e5+10;
int dot[2][sz*4], lg, rg, p, va;
int que(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[i][nu];
    else if(l>rg or r<lg) return -inf;
    else
    {
        int mid=(l+r)>>1;
        return max(que(i, nu*2, l, mid), que(i, nu*2+1, mid+1, r));
    }
}
void cha(int i, int nu, int l, int r)
{
    if(l==r) dot[i][nu]=max(dot[i][nu], va);
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(i, nu*2, l, mid);
        else cha(i, nu*2+1, mid+1, r);
        dot[i][nu]=max(dot[i][nu*2], dot[i][nu*2+1]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ma[ar[a]-a]=0;
    }
    ma[-inf]=0, ma[inf]=0;
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        (*it).second=m, m++;
    }
    for(int a=0; a<sz*4; a++)
    {
        dot[0][a]=-inf, dot[1][a]=-inf;
    }
    p=0, va=0, cha(0, 1, 0, m-1);
    int an=inf;
    for(int a=0; a<n; a++)
    {
        if(a+1<n)
        {
            auto it=ma.upper_bound(ar[a+1]-a);
            it--;
            lg=0, rg=(*it).second;
            va=que(0, 1, 0, m-1)+1;
            lg=0, rg=ma[ar[a+1]-(a+1)];
            va=max(va, que(1, 1, 0, m-1)+1);
            p=ma[ar[a+1]-(a+1)];
            cha(1, 1, 0, m-1);
            an=min(an, n-1-va);
        }
        lg=0, rg=ma[ar[a]-a];
        va=que(0, 1, 0, m-1)+1;
        p=ma[ar[a]-a];
        cha(0, 1, 0, m-1);
        an=min(an, n-va);
        if(a+1<n) an=min(an, n-va-1);
    }
    cout<<an;
}