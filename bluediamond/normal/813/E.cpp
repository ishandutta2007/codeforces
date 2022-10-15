#include <bits/stdc++.h>

using namespace std;

const int N=100000+7;
int n,k;
vector <int> p[N];
int b[N];

vector <int> mrg(vector <int> a, vector <int> b)
{
        vector <int> c;
        int pa=0, pb=0;
        int na=(int)a.size(), nb=(int)b.size();
        while (pa<na || pb<nb)
        {
                int t=0;
                if (pa==na)
                        t=2;
                if (pb==nb)
                        t=1;
                if (!t)
                        if (a[pa]<b[pb])
                                t=1;
                        else
                                t=2;
                if (t==1)
                        c.push_back(a[pa++]);
                else
                        c.push_back(b[pb++]);
        }
        return c;
}

vector <int> t[4*N];

void build(int v, int tl, int tr)
{
        if (tl==tr)
                t[v]={b[tl]};
        else
        {
                int tm=(tl+tr)/2;
                build(2*v, tl, tm);
                build(2*v+1, tm+1, tr);
                t[v]=mrg(t[2*v], t[2*v+1]);
        }
}

vector <int> ids;

void put(int v, int tl, int tr, int l, int r)
{
        if (r<tl || tr<l)
                return;
        if (l<=tl && tr<=r)
                ids.push_back(v);
        else
        {
                int tm=(tl+tr)/2;
                put(2*v, tl, tm, l, r);
                put(2*v+1, tm+1, tr, l, r);
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ///    freopen ("input", "r", stdin);

        cin>>n>>k;
        for (int i=1; i<=n; i++)
        {
                int wyn;
                cin>>wyn;
                p[wyn].push_back(i);
                if (p[wyn].size()>=k+1)
                        b[i]=p[wyn][(int)p[wyn].size()-k-1];
                else
                        b[i]=-1;
        }
        int q;
        cin>>q;
        build(1, 1, n);
        int sol=0;
        for (int i=1;i<=q;i++)
        {
                int l, r;
                cin>>l>>r;
                l=(l+sol)%n+1;
                r=(r+sol)%n+1;
                if (l>r)
                        swap(l, r);
                ids.clear();
                put(1, 1, n, l, r);
                sol=0;
                for (int j=l; j<=r; j++)
                        sol+=(b[j]<l);;
                int L=l;
                sol=0;
                for (auto &j : ids)
                {
                        int cur=0;
                        int l=0, r=t[j].size()-1;
                        while (l<=r)
                        {
                                int m=(l+r)/2;
                                if (t[j][m]<L)
                                {
                                        cur=m+1;
                                        l=m+1;
                                }
                                else
                                        r=m-1;
                        }
                        sol+=cur;
                }
                cout<<sol<<"\n";
        }

        return 0;
}