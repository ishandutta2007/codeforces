#include <bits/stdc++.h>
#define iter set <pair <int, int> >::iterator
using namespace std;
struct el
{
    int be=0, pref=0, suf=0, su=0;
};
const int sz=1e5+10, bl=60;
string s[sz];
int ar[sz], dot2[sz*4], i, lg, rg;
el dot[bl][sz*4], emp;
el recalc(el l, el r)
{
    el re;
    re.su=l.su+r.su;
    re.pref=l.pref;
    if(l.pref==l.su) re.pref+=r.pref;
    re.suf=r.suf;
    if(r.suf==r.su) re.suf+=l.suf;
    re.be=max(l.be, r.be);
    re.be=max(re.be, l.suf+r.pref);
    return re;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[i][nu].su=1;
        if(i<ar[l])
        {
            dot[i][nu].be=1;
            dot[i][nu].pref=1;
            dot[i][nu].suf=1;
        }
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[i][nu]=recalc(dot[i][nu*2], dot[i][nu*2+1]);
    }
}
void cha(int nu, int l, int r)
{
    if(l==r)
    {
        int va=0;
        if(i<ar[l]) va=1;
        dot[i][nu].be=va;
        dot[i][nu].pref=va;
        dot[i][nu].suf=va;
    }
    else
    {
        int mid=(l+r)>>1;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[i][nu]=recalc(dot[i][nu*2], dot[i][nu*2+1]);
    }
}
el que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[i][nu];
    else if(l>rg or r<lg) return emp;
    else
    {
        int mid=(l+r)>>1;
        return recalc(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
void build2(int nu, int l, int r)
{
    if(l==r) dot2[nu]=s[l].size();
    else
    {
        int mid=(l+r)>>1;
        build2(nu*2, l, mid);
        build2(nu*2+1, mid+1, r);
        dot2[nu]=max(dot2[nu*2], dot2[nu*2+1]);
    }
}
void cha2(int nu, int l, int r)
{
    if(l==r) dot2[nu]=s[l].size();
    else
    {
        int mid=(l+r)>>1;
        if(lg<=mid) cha2(nu*2, l, mid);
        else cha2(nu*2+1, mid+1, r);
        dot2[nu]=max(dot2[nu*2], dot2[nu*2+1]);
    }
}
int que2(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot2[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return max(que2(nu*2, l, mid), que2(nu*2+1, mid+1, r));
    }
}
void lcp(int p)
{
    ar[p]=0;
    for(int a=0; a<min(s[p].size(), s[p+1].size()); a++)
    {
        if(s[p][a]==s[p+1][a]) ar[p]++;
        else break;
    }
}
set <pair <int, int> > big;
int fi()
{
    iter it=big.begin();
    int an=0;
    while(it!=big.end())
    {
        vector <int> ve;
        int p=(*it).first;

        if(p>=lg and p<=rg)
        {
            p--;
            while(it!=big.end())
            {
                if((*it).first==p+1 and p+1<=rg)
                {
                    ve.push_back((*it).second), it++, p++;
                }
                else break;
            }
            int n=ve.size();
            int ri[n];
            stack <int> st;
            for(int a=0; a<n; a++)
            {
                while(st.size()>0)
                {
                    int nu=st.top();
                    if(ve[nu]>ve[a])
                    {
                        ri[nu]=a;
                        st.pop();
                    }
                    else break;
                }
                st.push(a);
            }
            while(st.size()>0)
            {
                ri[st.top()]=n, st.pop();
            }
            for(int a=n-1; a>=0; a--)
            {
                while(st.size()>0)
                {
                    int nu=st.top();
                    if(ve[nu]>ve[a])
                    {
                        an=max(an, (ri[nu]-a)*ve[nu]);
                        st.pop();
                    }
                    else break;
                }
                st.push(a);
            }
            while(st.size()>0)
            {
                int nu=st.top();
                an=max(an, (ri[nu]+1)*ve[nu]);
                st.pop();
            }
        }
        else it++;
    }
    return an;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n; a++)
    {
        cin>>s[a];
        if(a!=0)
        {
            lcp(a-1);
            if(ar[a-1]>bl) big.insert(make_pair(a-1, ar[a-1]));
        }
    }
    build2(1, 0, n-1);
    if(n>1)
    {
        for(i=0; i<bl; i++) build(1, 0, n-2);
    }
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            scanf("%d%d", &lg, &rg);
            lg--, rg--;
            int an=que2(1, 0, n-1);
            rg--;
            if(lg<=rg)
            {
                for(i=0; i<bl; i++)
                {
                    int cu=que(1, 0, n-2).be;
                    if(cu>0) an=max(an, (cu+1)*(i+1));
                }
                an=max(an, fi());
            }
            printf("%d\n", an);
        }
        else
        {
            int p;
            scanf("%d", &p);
            p--;
            cin>>s[p];
            if(p!=0)
            {
                if(ar[p-1]>bl) big.erase(make_pair(p-1, ar[p-1]));
                lcp(p-1);
                if(ar[p-1]>bl) big.insert(make_pair(p-1, ar[p-1]));
                lg=p-1;
                for(i=0; i<bl; i++) cha(1, 0, n-2);
            }
            if(p+1<n)
            {
                if(ar[p]>bl) big.erase(make_pair(p, ar[p]));
                lcp(p);
                if(ar[p]>bl) big.insert(make_pair(p, ar[p]));
                lg=p;
                for(i=0; i<bl; i++) cha(1, 0, n-2);
            }
            lg=p, cha2(1, 0, n-1);
        }
    }
}