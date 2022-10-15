#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int ll

struct T
{
        int l, r, w;
};

bool operator < (T a, T b)
{
        return a.w<b.w;
}

const int M=(int) 1e6+7;
const int N=(int) 3e5+7;
int n, m;
T a[N];
int tree[4*M], lazy[4*M];

void push(int v, int tl, int tr)
{
        if (!lazy[v]) return;
        tree[v]+=lazy[v];
        if (tl<tr)
        {
                lazy[2*v]+=lazy[v];
                lazy[2*v+1]+=lazy[v];
        }
        lazy[v]=0;
}

void add(int v, int tl, int tr, int l, int r, int x)
{
        push(v, tl, tr);
        if (tr<l||r<tl) return;
        if (l<=tl&&tr<=r)
        {
                lazy[v]+=x;
                push(v, tl, tr);
                return;
        }
        int tm=(tl+tr)/2;
        add(2*v, tl, tm, l, r, x);
        add(2*v+1, tm+1, tr, l, r, x);
        tree[v]=min(tree[2*v], tree[2*v+1]);
}

void add(int l, int r, int x)
{
        add(1, 1, m, l, r, x);
}

bool good()
{
        push(1, 1, m);
        return tree[1]>=1;
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      //  freopen ("input", "r", stdin);

        cin>>n>>m;
        for (int i=1; i<=n; i++)
        {
                cin>>a[i].l>>a[i].r>>a[i].w;
                a[i].r--;
        }
        sort(a+1, a+n+1);

        m--;

        int mn=(int) 1e9, l=1;
        for (int r=1; r<=n; r++)
        {
                add(a[r].l, a[r].r, +1);
                if (!good()) continue;
                while (1)
                {
                        assert(good());
                        add(a[l].l, a[l].r, -1);
                        l++;
                        if (good()) continue;
                        l--;
                        add(a[l].l, a[l].r, +1);
                        break;
                }
                mn=min(mn, a[r].w-a[l].w);
        }


        assert(mn!=(int) 1e9);
        cout<<mn<<"\n";




}