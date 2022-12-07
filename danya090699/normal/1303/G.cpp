#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
class LiChao
{
public:

    LiChao(T l, T r, string ty="min")
    {
        type = ty, L = l, R = r;
        T inf = sizeof(T)==4 ? INT_MAX : LLONG_MAX;

        tree=new pair <T, T>[(R-L+1)*4];
        for(int a=0; a<(R-L+1)*4; a++) tree[a]={0, inf};
    }

    ~LiChao()
    {
        delete [] tree;
    }

    void insert(T k, T b)
    {
        if(type=="max") k=-k, b=-b;
        ins(1, L, R, {k, b});
    }

    T query(T x)
    {
        int re=que(1, L, R, x);
        if(type=="max") re=-re;
        return re;
    }

private:

    void ins(int nu, T l, T r, pair <T, T> line)
    {
        int mid=(l+r)>>1;
        bool ly=f(line, l) < f(tree[nu], l);
        bool my=f(line, mid) < f(tree[nu], mid);

        if(my) swap(line, tree[nu]);

        if(l!=r)
        {
            if(ly!=my) ins(nu*2, l, mid, line);
            else ins(nu*2+1, mid+1, r, line);
        }
    }

    T que(int nu, T l, T r, T x)
    {
        T y=f(tree[nu], x);

        if(l==r) return y;
        else
        {
            T mid=(l+r)>>1;
            if(x<=mid) return min(y, que(nu*2, l, mid, x));
            else return min(y, que(nu*2+1, mid+1, r, x));
        }
    }

    T f(pair <T, T> line, T x)
    {
        return line.first*x+line.second;
    }

    string type;
    T L, R;
    pair <T, T> *tree;
};

const int sz=2e5+10;
vector <int> sv[sz];
int w[sz], si[sz];
void siz(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) siz(ne, v), si[v]+=si[ne];
    }
}
int find_ce(int v, int pr, int n)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr and si[ne]*2>n) return find_ce(ne, v, n);
    }
    if(pr!=-1) si[pr]=n-si[v];
    return v;
}

struct leaf
{
    int h, su, pref, suf;
};
vector <vector <leaf> > sp;

void dfs2(int v, int pr, int h, int su, int pref, int suf)
{
    h++, su+=w[v], pref+=su, suf+=h*w[v];
    if(sv[v].size()==1) sp.back().push_back({h, su, pref, suf});

    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs2(ne, v, h, su, pref, suf);
    }
}
int an=0;
void dfs(int v, int n)
{
    siz(v, -1);
    int ce=find_ce(v, -1, n);

    for(int a=0; a<sv[ce].size(); a++)
    {
        sp.push_back(vector <leaf>());
        dfs2(sv[ce][a], ce, 0, 0, 0, 0);
    }
    for(int i=0; i<2; i++)
    {
        LiChao <int> hull(0, n, "max");
        hull.insert(0, 0);
        for(int a=0; a<sp.size(); a++)
        {
            for(int b=0; b<sp[a].size(); b++)
            {
                leaf &cu=sp[a][b];
                an=max(an, cu.pref+(cu.h+1)*w[ce]+hull.query(cu.h+1));
            }
            for(int b=0; b<sp[a].size(); b++)
            {
                leaf &cu=sp[a][b];
                hull.insert(cu.su, cu.suf);
            }
        }
        reverse(sp.begin(), sp.end());
    }
    sp.clear();
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a];
        for(int b=0; b<sv[ne].size(); b++)
        {
            if(sv[ne][b]==ce) sv[ne].erase(sv[ne].begin()+b);
        }
        dfs(ne, si[ne]);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++) scanf("%lld", &w[a]);
    dfs(0, n);
    cout<<an;
}