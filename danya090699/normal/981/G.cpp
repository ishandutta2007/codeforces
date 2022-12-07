#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=2e5+10;
int n, q;
map <int, int> ot[sz];
int dot[sz*4], add[sz*4], add2[sz*4];
int lg, rg, t;
void push(int nu)
{
    add[nu*2]=(1ll*add[nu*2]*add[nu])%mod;
    add2[nu*2]=(1ll*add2[nu*2]*add[nu]+add2[nu])%mod;

    add[nu*2+1]=(1ll*add[nu*2+1]*add[nu])%mod;
    add2[nu*2+1]=(1ll*add2[nu*2+1]*add[nu]+add2[nu])%mod;

    add[nu]=1, add2[nu]=0;
}
void recalc(int nu, int l, int r)
{
    int mid=(l+r)>>1;
    int ql=mid-l+1, qr=r-mid;
    dot[nu]=(1ll*dot[nu*2]*add[nu*2]+1ll*ql*add2[nu*2]+1ll*dot[nu*2+1]*add[nu*2+1]+1ll*qr*add2[nu*2+1])%mod;
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if(t==0)
        {
            add[nu]=(add[nu]*2)%mod;
            add2[nu]=(add2[nu]*2)%mod;
        }
        else add2[nu]=(add2[nu]+1)%mod;
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu, l, r);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        int qq=r-l+1;
        //cout<<l<<" "<<r<<" "<<(1ll*dot[nu]*add[nu]+1ll*qq*add2[nu])%mod<<"\n";
        return (1ll*dot[nu]*add[nu]+1ll*qq*add2[nu])%mod;
    }
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        int re=(que(nu*2, l, mid)+que(nu*2+1, mid+1, r))%mod;
        recalc(nu, l, r);
        return re;
    }
}
void ins(int x, int l, int r)
{
    auto itr=ot[x].upper_bound(r);
    auto itl=itr;
    int pr=r+1, rel=l, rer=r;
    vector <map <int, int>::iterator > sp;
    while(itl!=ot[x].begin())
    {
        itl--;
        int ll=(*itl).first, rr=(*itl).second;
        if(rr<l) break;

        rel=min(rel, ll), rer=max(rer, rr);
        if(rr+1<pr)
        {
            lg=rr+1, rg=pr-1, t=1;
            cha(1, 0, n-1);
            //cout<<lg<<" "<<rg<<" "<<t<<"\n";
        }
        pr=ll;
        ll=max(ll, l), rr=min(rr, r);
        lg=ll, rg=rr, t=0;
        cha(1, 0, n-1);
        //cout<<lg<<" "<<rg<<" "<<t<<"\n";
        sp.push_back(itl);
    }
    if(pr>l)
    {
        lg=l, rg=pr-1, t=1;
        cha(1, 0, n-1);
        //cout<<lg<<" "<<rg<<" "<<t<<"\n";
    }
    while(sp.size())
    {
        ot[x].erase(sp.back());
        sp.pop_back();
    }
    ot[x][rel]=rer;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int a=0; a<n*4; a++) add[a]=1;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l--, r--;
            ins(x, l, r);
            //for(int b=1; b<6; b++) cout<<add[b]<<" ";
            //cout<<"\n\n";
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            lg=l, rg=r;
            int re=que(1, 0, n-1);
            printf("%d\n", re);
        }
    }
    //for(auto it=ot[2].begin(); it!=ot[2].end(); it++) cout<<(*it).first<<" "<<(*it).second<<"\n";
}