#include <bits/stdc++.h>
#define iter map <re, vector <int>, comp>::iterator
#define pair pair <int, bool>
using namespace std;
const int sz=1e5+10;
int n, q, lg, rg, err=0;
struct re
{
    int u, v;
};
re nre;
struct comp
{
    bool operator() (const re &a, const re &b) const
    {
        if(a.u!=b.u) return a.u<b.u;
        else return a.v<b.v;
    }
};
vector <re> dot[sz*4];
void ins(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].push_back(nre);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        ins(nu*2, l, mid);
        ins(nu*2+1, mid+1, r);
    }
}
struct ve
{
    int pr, si=1;
    bool di=0;
};
ve dsu[sz];
pair find_se(int v)
{
    if(dsu[v].pr==v) return make_pair(v, 0);
    else
    {
        pair an=find_se(dsu[v].pr);
        an.second^=dsu[v].di;
        return an;
    }
}
stack <re> st;
void add(re uv)
{
    pair u=find_se(uv.u), v=find_se(uv.v);
    int s1=u.first, s2=v.first;
    bool d1=u.second, d2=v.second;
    re nre;
    if(s1!=s2)
    {
        if(dsu[s1].si<dsu[s2].si)
        {
            swap(s1, s2), swap(d1, d2);
        }
        dsu[s1].si+=dsu[s2].si;
        dsu[s2].pr=s1;
        dsu[s2].di=(d1^d2^1);
        nre.u=s1, nre.v=s2;
    }
    else
    {
        if(d1!=d2) nre.u=-1;
        else
        {
            nre.u=-2, err++;
        }
    }
    st.push(nre);
}
void del()
{
    int s1=st.top().u, s2=st.top().v;
    if(s1>=0)
    {
        dsu[s1].si-=dsu[s2].si;
        dsu[s2].pr=s2;
        dsu[s2].di=0;
    }
    else if(s1==-2) err--;
    st.pop();
}
void solve(int nu, int l, int r)
{
    for(int a=0; a<dot[nu].size(); a++) add(dot[nu][a]);
    if(l==r)
    {
        if(err==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else
    {
        int mid=(l+r)/2;
        solve(nu*2, l, mid);
        solve(nu*2+1, mid+1, r);
    }
    for(int a=0; a<dot[nu].size(); a++) del();
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int a=0; a<n; a++) dsu[a].pr=a;
    map <re, vector <int>, comp> ma;
    for(int a=0; a<q; a++)
    {
        re nel;
        scanf("%d%d", &nel.u, &nel.v);
        nel.u--, nel.v--;
        ma[nel].push_back(a);
    }
    for(iter it=ma.begin(); it!=ma.end(); it++)
    {
        nre.u=(*it).first.u, nre.v=(*it).first.v;
        vector <int> &ve=(*it).second;
        int m=ve.size();
        if(m%2==1) ve.push_back(q);
        for(int a=0; a<m; a+=2)
        {
            lg=ve[a], rg=ve[a+1]-1;
            ins(1, 0, q-1);
        }
    }
    solve(1, 0, q-1);
}