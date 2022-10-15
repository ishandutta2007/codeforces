#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+7;
const int M=N*(N-1)/2;
int n, m, q, e[M][3], last[N], t[N], event, shift[N];
vector<int> inds[4*M];

void upd(int a)
{
        if (last[a]<event)
        {
                shift[a]=0;
                last[a]=event;
                t[a]=a;
        }
}

pair<int, int> root(int a)
{
        upd(a);
        if (t[a]==a)
                return {a, 0};
        else
        {
                auto it=root(t[a]);
                int rt=it.first, col=it.second^shift[a];
                assert(shift[rt]==0); /// delete this later!!!!!!!!!!!!!!!!!!!!!!!!
                t[a]=rt;
                shift[a]=col;
                return {rt, col};
        }
}

int colonly(int a)
{
        upd(a);
        if (t[a]==a)
        {
                assert(shift[a]==0);
                return a;
        }
        else
        {
                return shift[a]^colonly(t[a]);
        }
}

int unite(int a, int b)
{
        auto x=root(a);
        auto y=root(b);
        int aa=a, bb=b;
        a=x.first;
        b=y.first;
        int ca=x.second, cb=y.second;
        if (a==b)
        {
                if (ca==cb)
                {
                        return 1;
                }
                else
                {
                        return 0;
                }
        }

        t[a]=b;
        assert(shift[a]==0);
        if (colonly(aa)==colonly(bb))
        {
                shift[a]=1;
        }

        assert(colonly(aa)!=colonly(bb));
        return 2;
}

void build(int v, int tl, int tr)
{
        if (tl==tr)
        {
                inds[v]={tl};
                return;
        }
        /// daca o muchie nu conteaza pe [l, r] nu o sa conteze pe alt interval mai mare deoarece ele o sa fie oricum unite
        int tm=(tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        event++;
        vector<int> &a=inds[2*v];
        vector<int> &b=inds[2*v+1];
        vector<int> c;
        /// a = descrescator
        /// b = descrescator
        int ya=a.size(), yb=b.size();
        int pa=0, pb=0;
        while (pa<ya && pb<yb)
        {
                if (e[a[pa]][2]>e[b[pb]][2])
                {
                        c.push_back(a[pa++]);
                }
                else
                {
                        c.push_back(b[pb++]);
                }
        }
        while (pa<ya)
        {
                c.push_back(a[pa++]);
        }
        while (pb<yb)
        {
                c.push_back(b[pb++]);
        }
        for (auto &it : c)
        {
                int sens=unite(e[it][0], e[it][1]);
                if (sens)
                {
                        inds[v].push_back(it);
                        if (sens==1)
                                break;
                }
        }
       /// cout<<tl<<"..."<<tr<<" : "<<(int) inds[v].size()<<"\n";
}

vector<int> ed;
int ans=-1;

void place(int v, int tl, int tr, int l, int r)
{
        if (tr<l||r<tl)
        {
                return;
        }
        if (l<=tl&&tr<=r)
        {
                event++;
                vector<int> &a=ed;
                vector<int> &b=inds[v];

                vector<int> c;
                /// a = descrescator
                /// b = descrescator
                int ya=a.size(), yb=b.size();
                int pa=0, pb=0;
                while (pa<ya && pb<yb)
                {
                        if (e[a[pa]][2]>e[b[pb]][2])
                        {
                                c.push_back(a[pa++]);
                        }
                        else
                        {
                                c.push_back(b[pb++]);
                        }
                }
                while (pa<ya)
                {
                        c.push_back(a[pa++]);
                }
                while (pb<yb)
                {
                        c.push_back(b[pb++]);
                }
                ans=-1;
                vector<int> sol;
                for (auto &it : c)
                {
                        int sens=unite(e[it][0], e[it][1]);
                        if (sens)
                        {
                                sol.push_back(it);
                                if (sens==1)
                                {
                                        ans=e[it][2];
                                        break;
                                }
                        }
                }
                ed=sol;
                return;
        }
        int tm=(tl+tr)/2;
        place(2*v, tl, tm, l, r);
        place(2*v+1, tm+1, tr, l, r);
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        ///freopen ("input", "r", stdin);

        cin>>n>>m>>q;
        for (int i=1; i<=m; i++)
        {
                cin>>e[i][0]>>e[i][1]>>e[i][2];
        }
        build(1, 1, m);
       /// return 0;
        for (int i=1; i<=q; i++)
        {
                int l, r;
                cin>>l>>r;
                ed.clear();
                ans=-1;
                place(1, 1, m, l, r);
                cout<<ans<<"\n";
                ///cout<<(int) ed.size()<<"\n";
        }
        return 0;
}