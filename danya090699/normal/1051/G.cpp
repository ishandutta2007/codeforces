#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
vector <int> fen[2][sz*2];
int que(vector <int> &fe, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fe[p], p=(p&(p+1))-1;
    }
    return re;
}
void cha(vector <int> &fe, int p, int va)
{
    while(p<fe.size())
    {
        fe[p]+=va, p=p|(p+1);
    }
}
map <int, int, greater <int> > ma[sz*2];
int cnu[sz*2], gr[sz*2], su[sz*2], an=0;
void add(int nu, int x, int y, int ty)
{
    int p=ma[nu][y];
    int lq=que(fen[0][nu], p), lsu=que(fen[1][nu], p);
    int x2=gr[nu]+lq;

    an+=(x2-x)*y;

    if(ty==0) an+=su[nu]-lsu;
    else an-=lsu;

    cha(fen[0][nu], p, 1), cha(fen[1][nu], p, y), su[nu]+=y;
}
void merge(int u, int v)
{
    if(ma[u].size()<ma[v].size()) swap(u, v);
    for(auto it=ma[v].begin(); it!=ma[v].end(); it++) ma[u][(*it).first]=0;
    int fi=gr[v], la=gr[v]+ma[v].size();
    if(gr[v]<gr[u]) la--;
    for(fi; fi<=la; fi++) cnu[fi]=u;
    gr[u]=min(gr[u], gr[v]);
}
main()
{
    for(int a=0; a<sz*2; a++)
    {
        cnu[a]=a, gr[a]=a;
    }
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n][4];
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%lld%lld", &x, &y);
        int cl=cnu[x];
        int cr=cnu[gr[cl]+ma[cl].size()+1];
        ar[a][0]=x, ar[a][1]=y, ar[a][2]=cl, ar[a][3]=cr;
        ma[cl][y]=0, merge(cl, cr);
    }
    for(int a=0; a<sz*2; a++)
    {
        if(ma[a].size())
        {
            int m=0;
            for(auto it=ma[a].begin(); it!=ma[a].end(); it++)
            {
                (*it).second=m, m++;
            }
            fen[0][a].resize(m), fen[1][a].resize(m);
        }
        gr[a]=a;
    }
    for(int a=0; a<n; a++)
    {
        int x=ar[a][0], y=ar[a][1], cl=ar[a][2], cr=ar[a][3];
        add(cl, x, y, 0);
        if(ma[cl].size()>ma[cr].size())
        {
            int x2=gr[cr];
            for(auto it=ma[cr].begin(); it!=ma[cr].end(); it++)
            {
                add(cl, x2, (*it).first, 0), x2++;
            }
        }
        else
        {
            int x2=gr[cl];
            for(auto it=ma[cl].begin(); it!=ma[cl].end(); it++)
            {
                gr[cr]--, add(cr, x2, (*it).first, 1), x2++;
            }
        }
        printf("%lld\n", an);
    }
}