#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, bl=500;
mt19937 rnd(time(0));
int al, mod, arr[sz*2], *po=arr+sz, st[sz];

int power(int x, int y)
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

bool prime(int x)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0) return false;
    }
    return true;
}
int randnum(int x)
{
    x+=rnd()%10000;
    while(!prime(x)) x++;
    return x;
}
struct el
{
    vector <int> open;
    int closeh, closeq;
};
void build(int *l, int *r, el &seg)
{
    seg.open.clear(), seg.closeh=0, seg.closeq=0;
    int n=0;
    for(l; l!=r; l++)
    {
        int x=(*l);
        if(x>0) st[n++]=x;
        else
        {
            if(n)
            {
                if(st[n-1]!=-x)
                {
                    seg.closeq=-1;
                    break;
                }
                else n--;
            }
            else
            {
                seg.closeh=(seg.closeh+1ll*po[seg.closeq++]*(-x))%mod;
            }
        }
    }
    seg.open.push_back(0);
    for(int a=0; a<n; a++)
    {
        seg.open.push_back((seg.open.back()+1ll*po[n-1-a]*st[a])%mod);
    }
}
bool add(vector <pair <vector <int>*, int> > &st, el &seg)
{
    int n=seg.closeq, h=0;
    if(n==-1) return false;

    while(n and st.size())
    {
        vector <int> &open=(*st.back().first);
        int r=st.back().second, l=r-min(st.back().second, n);
        int x=open[r]-open[l];

        if(x<0) x+=mod;
        h=(h+1ll*x*po[seg.closeq-n-(open.size()-1-r)])%mod;
        n-=(r-l), st.back().second=l;
        if(l==0) st.pop_back();
    }

    if(n or h!=seg.closeh) return false;

    if(seg.open.size()>1)
    {
        st.push_back({&seg.open, seg.open.size()-1});
    }

    return true;
}
main()
{
    int n, k;
    cin>>n>>k;
    al=randnum(k+1), mod=randnum(1e9);
    po[0]=1;
    for(int a=1; a<=n; a++)
    {
        po[a]=1ll*po[a-1]*al%mod;
        po[-a]=power(po[a], mod-2);
    }

    int s[n];
    el sq[n];
    for(int a=0; a<n; a++) scanf("%d", &s[a]);
    for(int l=0; l<n; l+=bl)
    {
        int r=min(n, l+bl);
        build(s+l, s+r, sq[l]);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int p;
            scanf("%d", &p);
            p--, scanf("%d", &s[p]);
            int l=p-p%bl, r=min(n, l+bl);
            build(s+l, s+r, sq[l]);
        }
        else
        {
            int lg, rg, ok=1;
            scanf("%d%d", &lg, &rg);
            lg--, rg;
            vector <pair <vector <int>*, int> > st;
            vector <el*> sp;
            for(int l=0; l<n; l+=bl)
            {
                int r=min(l+bl, n);
                int ll=max(l, lg), rr=min(r, rg);
                //cout<<ll<<" "<<rr<<"\n";
                if(ll<rr)
                {
                    if(ll==l and rr==r) ok&=add(st, sq[l]);
                    else
                    {
                        sp.push_back(new el);
                        build(s+ll, s+rr, *sp.back());
                        ok&=add(st, *sp.back());
                    }
                }

                if(!ok) break;
            }
            while(sp.size())
            {
                delete sp.back();
                sp.pop_back();
            }

            if(st.size()) ok=0;
            printf(ok ? "Yes\n" : "No\n");
        }
    }
}