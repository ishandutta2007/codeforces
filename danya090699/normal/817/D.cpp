#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int dot[sz*4], nva, lg, rg, f=0, n;
int recalc(int a, int b)
{
    if(f==0) return max(a, b);
    else return min(a, b);
}
void ins(int nu, int l, int r)
{
    if(l==r) dot[nu]=nva;
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) ins(nu*2, l, mid);
        else ins(nu*2+1, mid+1, r);
        dot[nu]=recalc(dot[nu*2], dot[nu*2+1]);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg)
    {
        if(f==0) return -1;
        else return n;
    }
    else
    {
        int mid=(l+r)/2;
        return recalc(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    long long ans=0;
    cin>>n;
    int ar[n], le[n][2];
    for(int a=0; a<sz*4; a++) dot[a]=-1;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        lg=0, rg=ar[a];
        le[a][0]=a-que(1, 0, sz-1);
        lg=ar[a], rg=sz-1;
        le[a][1]=a-que(1, 0, sz-1);
        lg=ar[a], nva=a;
        ins(1, 0, sz-1);
    }
    f=1;
    for(int a=0; a<sz*4; a++) dot[a]=n;
    for(int a=n-1; a>=0; a--)
    {
        int ri;
        lg=0, rg=ar[a]-1;
        ri=que(1, 0, sz-1)-a;
        ans+=1ll*(-ar[a])*le[a][0]*ri;
        lg=ar[a]+1, rg=sz-1;
        ri=que(1, 0, sz-1)-a;
        ans+=1ll*ar[a]*le[a][1]*ri;
        lg=ar[a], nva=a;
        ins(1, 0, sz-1);
    }
    cout<<ans;
}