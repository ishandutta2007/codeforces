#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int *st, ar[sz], mod;
char s[sz];
struct el
{
    bool l, r;
    int hash, q, n;
};
el dot[sz*4];
el recalc(el l, el r)
{
    el re;
    if(l.r and r.l)
    {
        re.l=(l.l and (l.n-l.q>1));
        re.r=(r.r and (r.n-r.q>1));
        l.hash-=st[l.n-l.q-1];
        if(l.hash<0) l.hash+=mod;
        r.hash--;
        if(r.hash<0) r.hash+=mod;
        re.hash=(l.hash+1ll*st[l.n-l.q-2]*r.hash)%mod;
        re.q=l.q+r.q+2;
        re.n=l.n+r.n;
    }
    else
    {
        re.l=(l.l or (r.l and l.q==l.n));
        re.r=(r.r or (l.r and r.q==r.n));
        re.hash=(l.hash+1ll*st[l.n-l.q]*r.hash)%mod;
        re.q=l.q+r.q;
        re.n=l.n+r.n;
    }
    return re;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        if(s[l]=='0') dot[nu]={0, 0, 0, 0, 1};
        else dot[nu]={1, 1, 1, 0, 1};
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=recalc(dot[nu*2], dot[nu*2+1]);
    }
}
int lg, rg;
el que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else
    {
        int mid=(l+r)>>1;
        if(rg<=mid) return que(nu*2, l, mid);
        else if(lg>mid) return que(nu*2+1, mid+1, r);
        else
        {
            return recalc(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
        }
    }
}
bool prime(int x)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0) return false;
    }
    return true;
}
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
main()
{
    srand(time(0));
    mod=1e9+rand();
    while(!prime(mod)) mod++;

    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    ar[0]=po(2, mod-2);
    ar[1]=1;
    st=ar+1;
    for(int a=1; a<=n; a++) st[a]=(st[a-1]*2)%mod;
    scanf("%s", s);
    build(1, 0, n-1);

    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l1, l2, len;
        scanf("%d%d%d", &l1, &l2, &len);
        l1--, l2--, len--;
        lg=l1, rg=l1+len;
        el s1=que(1, 0, n-1);
        lg=l2, rg=l2+len;
        el s2=que(1, 0, n-1);

        printf((s1.hash==s2.hash and s1.q==s2.q) ? "Yes\n" : "No\n");
    }
}