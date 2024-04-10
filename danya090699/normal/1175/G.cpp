#include <bits/stdc++.h>
using namespace std;
const int sz=2e4+10, inf=5e8;

struct CHT_line
{
    int k, b, r;
    operator < (const CHT_line &x) const
    {
        return r>x.r;
    }
};

class CHT
{
public:

    CHT(string k, string f)
    {
        if(f=="min")
        {
            dy=1;
            if(k=="inc") dx=1;
            else dx=-1;
        }
        else
        {
            dy=-1;
            if(k=="inc") dx=-1;
            else dx=1;
        }
    }

    void insert(int k, int b)
    {
        k*=(dx*dy), b*=dy;
        while(hull.size())
        {
            int k2=hull.back().k, b2=hull.back().b, r2=hull.back().r, r;
            if(k==k2)
            {
                if(b>b2) break;
                else hull.pop_back();
            }
            else
            {
                if(b<=b2) r=(b2-b)/(k-k2);
                else r=-((b-b2)/(k-k2)+1);

                if(r>=r2) hull.pop_back();
                else
                {
                    hull.push_back({k, b, r});
                    break;
                }
            }
        }
        if(hull.size()==0) hull.push_back({k, b, inf});
    }

    int query(int x)
    {
        x*=dx;
        CHT_line cu={0, 0, x};
        int p=upper_bound(hull.begin(), hull.end(), cu)-hull.begin()-1;
        return hull[p].k*x+hull[p].b;
    }

    vector <CHT_line> hull;

private:

    int dx, dy;
    static const int inf=2e9;
};

vector <CHT> dot(sz*4, CHT("dec", "min"));
int n, k, dp[sz];
void build(int nu, int l, int r)
{
    dot[nu].hull.clear();
    for(int a=l; a<=r; a++) dot[nu].insert(n-a, dp[a]);
    if(l!=r)
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
    }
}
int lg, rg, mx;
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu].query(mx);
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)>>1;
        return min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
vector <int> sv[sz], sp[sz];
int pr[sz], si[sz], hld[sz];
void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), si[v]+=si[ne];
    }
}
void dfs2(int v)
{
    int be=-1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(be==-1 or si[ne]>si[be]) be=ne;
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne==be) hld[ne]=hld[v];
        else hld[ne]=ne;
        dfs2(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    int ar[n], l[n];
    dp[0]=0;
    vector <int> st;
    st.push_back(-1);
    for(int a=0; a<n; a++)
    {
        cin>>ar[a], dp[a+1]=inf;
        while(st.back()!=-1 and ar[st.back()]<=ar[a]) st.pop_back();
        l[a]=st.back()+1;
        if(st.back()==-1) pr[a]=a;
        else
        {
            pr[a]=st.back();
            sv[pr[a]].push_back(a);
        }
        st.push_back(a);
    }
    for(int a=0; a<n; a++)
    {
        if(pr[a]==a) dfs(a), hld[a]=a, dfs2(a);
    }
    for(int a=0; a<n; a++)
    {
        int v=a;
        while(1)
        {
            sp[v].push_back(a+1);
            v=hld[v];
            if(pr[v]==v) break;
            v=pr[v];
        }
    }
    for(int i=1; i<=k; i++)
    {
        build(1, 0, n-1);
        for(int a=0; a<=n; a++) dp[a]=inf;
        vector <CHT> hull(n, CHT("dec", "min"));
        for(int a=0; a<n; a++)
        {
            int nu=hld[a];
            lg=l[a], rg=a, mx=ar[a];
            int va=que(1, 0, n-1);
            hull[nu].insert(mx, va-n*mx);
            for(int b=0; b<sp[a].size(); b++)
            {
                int p=sp[a][b];
                dp[p]=min(dp[p], hull[nu].query(p));
            }
        }
    }
    cout<<dp[n];
}