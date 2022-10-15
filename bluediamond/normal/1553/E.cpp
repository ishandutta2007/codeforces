#include <bits/stdc++.h>

using namespace std;

vector<int> t;

void init(int n)
{
        t.clear();
        t.resize(n);
        iota(t.begin(), t.end(), 0);
}

int root(int a)
{
        if (t[a]==a)
                return a;
        else
                return t[a]=root(t[a]);
}

void unite(int a, int b)
{
        t[root(a)]=root(b);
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

///        freopen ("input", "r", stdin);

        int tt;
        cin>>tt;
        while (tt--)
        {
                int n, m;
                cin>>n>>m;
                vector<int> a(n), cnt(n, 0);
                for (auto &x:a)
                {
                        cin>>x;
                        x--;
                }
                for (int i=0; i<n; i++)
                        cnt[(i-a[i]+n)%n]++;
                vector<int> sol;
                for (int shift=0; shift<n; shift++)
                {
                        if (cnt[shift]<n/3)
                                continue;
                        /// trebuie macar n/3 sa fie egale
                        vector<int> p(n);
                        for (int i=0; i<n; i++)
                                p[i]=(i-shift+n)%n;
                        init(n);
                        for (int i=0; i<n; i++)
                                unite(p[i], a[i]);
                        int comps=0;
                        for (int i=0; i<n; i++)
                                comps+=(t[i]==i);
                        if (n-comps<=m)
                                sol.push_back(shift);
                }
                cout<<(int) sol.size()<<" ";
                for (auto &i : sol)
                        cout<<i<<" ";
                cout<<"\n";
        }
        return 0;
}