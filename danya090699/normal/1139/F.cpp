#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sp[sz*4], fen[sz*4];
int ar[sz*2][4];
void fen_cha(int i, int p, int va)
{
    while(p<fen[i].size())
    {
        fen[i][p]+=va, p=p|(p+1);
    }
}
int fen_que(int i, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[i][p], p=(p&(p+1))-1;
    }
    return re;
}
void build(int nu, int l, int r)
{
    sort(sp[nu].begin(), sp[nu].end());
    fen[nu].resize(sp[nu].size(), 0);
    if(l!=r)
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
    }
}
int p, va;
void ins(int nu, int l, int r)
{
    sp[nu].push_back(va);
    if(l!=r)
    {
        int mid=(l+r)>>1;
        if(p<=mid) ins(nu*2, l, mid);
        else ins(nu*2+1, mid+1, r);
    }
}
void cha(int nu, int l, int r)
{
    int i=lower_bound(sp[nu].begin(), sp[nu].end(), va)-sp[nu].begin();
    fen_cha(nu, i, 1);
    if(l!=r)
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
    }
}
int lg, rg, rr;
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        int i=upper_bound(sp[nu].begin(), sp[nu].end(), rr)-sp[nu].begin();
        return fen_que(nu, i-1);
    }
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
bool comp(int a, int b)
{
    if(ar[a][1]!=ar[b][1]) return ar[a][1]>ar[b][1];
    else return ar[a][0]<ar[b][0];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    map <int, int> ma;
    for(int a=0; a<n; a++) ar[a][0]=-1, scanf("%d", &ar[a][2]);
    for(int a=0; a<n; a++) scanf("%d", &ar[a][1]);
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a][3]);
        ar[a][3]+=ar[a][2];
        ar[a][2]=ar[a][3]-ar[a][2]*2;
        ma[ar[a][2]]=0;
    }
    int n2=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=n2, n2++;
    for(int a=0; a<n; a++)
    {
        p=ma[ar[a][2]], va=ar[a][3];
        ins(1, 0, n2-1);
    }
    build(1, 0, n2-1);
    for(int a=0; a<m; a++) ar[a+n][0]=a, scanf("%d", &ar[a+n][2]), ar[a+n][1]=ar[a+n][2];
    for(int a=0; a<m; a++)
    {
        scanf("%d", &ar[a+n][3]);
        ar[a+n][3]+=ar[a+n][2];
        ar[a+n][2]=ar[a+n][3]-ar[a+n][2]*2;
    }
    int pp[n+m], an[m];
    for(int a=0; a<n+m; a++) pp[a]=a;
    sort(pp, pp+n+m, comp);

    for(int i=0; i<n+m; i++)
    {
        int a=pp[i];
        if(ar[a][0]==-1)
        {
            p=ma[ar[a][2]], va=ar[a][3];
            cha(1, 0, n2-1);
        }
        else
        {
            int num=ar[a][0];
            auto itl=ma.lower_bound(ar[a][2]), itr=ma.upper_bound(ar[a][3]);
            if(itl!=itr)
            {
                lg=(*itl).second, itr--, rg=(*itr).second, rr=ar[a][3];
                an[num]=que(1, 0, n2-1);
            }
            else an[num]=0;
        }
    }
    for(int a=0; a<m; a++) printf("%d ", an[a]);
}