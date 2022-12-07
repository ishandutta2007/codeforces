#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
struct el
{
    int q=0, mid;
    long long inv=0;
    vector <int> sp, fen;
    el *l=0, *r=0;
};

int w[sz];
vector <int> sp[sz];
void build(el &v, int l, int r)
{
    if(l==r)
    {
        v.sp=sp[l];
        sort(v.sp.begin(), v.sp.end());
        v.fen.resize(v.sp.size());
    }
    else
    {
        v.mid=l;
        for(int a=l+1; a<r; a++)
        {
            if(w[a]<w[v.mid]) v.mid=a;
        }
        v.l=new el, build(*v.l, l, v.mid);
        v.r=new el, build(*v.r, v.mid+1, r);

        vector <int> &L=(*v.l).sp;
        vector <int> &R=(*v.r).sp;
        v.sp.resize(L.size()+R.size());
        merge(L.begin(), L.end(), R.begin(), R.end(), v.sp.begin());
        v.fen.resize(L.size()+R.size());
    }
}
void fen_cha(vector <int> &fen, int p, int va)
{
    while(p<fen.size())
    {
        fen[p]+=va, p=p|(p+1);
    }
}
int fen_que(vector <int> &fen, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[p], p=(p&(p+1))-1;
    }
    return re;
}
long long an=0;
void cha(el &v, int p, int x, int add)
{
    if(v.l!=0)
    {
        el &l=*v.l, &r=*v.r;
        an-=min(v.inv, 1ll*l.q*r.q-v.inv);

        if(p<=v.mid)
        {
            int i=lower_bound(r.sp.begin(), r.sp.end(), x)-r.sp.begin()-1;
            v.inv+=fen_que(r.fen, i)*add;

            i=lower_bound(l.sp.begin(), l.sp.end(), x)-l.sp.begin();
            fen_cha(l.fen, i, add);

            l.q+=add;

            cha(l, p, x, add);
        }
        else
        {
            int i=upper_bound(l.sp.begin(), l.sp.end(), x)-l.sp.begin()-1;
            v.inv+=(l.q-fen_que(l.fen, i))*add;

            i=lower_bound(r.sp.begin(), r.sp.end(), x)-r.sp.begin();
            fen_cha(r.fen, i, add);

            r.q+=add;

            cha(r, p, x, add);
        }

        an+=min(v.inv, 1ll*l.q*r.q-v.inv);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        sp[a].push_back(ar[a]);
    }
    for(int a=0; a<n-1; a++) scanf("%d", &w[a]);
    int q;
    cin>>q;
    int qu[q][2];
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &qu[a][0], &qu[a][1]);
        qu[a][0]--, qu[a][1]--;
        int i=qu[a][0], j=qu[a][1];
        if(i!=j)
        {
            swap(ar[i], ar[j]);
            sp[i].push_back(ar[i]);
            sp[j].push_back(ar[j]);
        }
    }
    for(int a=q-1; a>=0; a--) swap(ar[qu[a][0]], ar[qu[a][1]]);

    el rt;
    build(rt, 0, n-1);
    for(int a=0; a<n; a++) cha(rt, a, ar[a], 1);

    for(int a=0; a<q; a++)
    {
        int i=qu[a][0], j=qu[a][1];
        if(i!=j)
        {
            cha(rt, i, ar[i], -1);
            cha(rt, j, ar[j], -1);
            swap(ar[i], ar[j]);
            cha(rt, i, ar[i], 1);
            cha(rt, j, ar[j], 1);
        }
        printf("%lld\n", an);
    }
}