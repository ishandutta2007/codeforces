#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 200000, INF = 2000000000;
struct Rec
{
    int x, p1, p2, num;
}rec[MAXN * 4];

struct Sec
{
    int l, r, t;
}Bus[MAXN], Peo[MAXN];
struct Ery
{
    int l, r, t, p, num;
}q[MAXN * 4];

struct Pair
{
    int val, num;
    friend int operator <(Pair a,Pair b)
    {
        return a.val < b.val;
    }
};
set <Pair> W[MAXN * 4];
int tot, Index, N, M, Ans[MAXN];

int cmpx(Rec a,Rec b)
{
    return a.x < b.x;
}

void Init()
{
    scanf("%d %d",&N,&M);
    for(int i = 1;i <= N;i++)
    {
        scanf("%d %d %d",&Bus[i].l,&Bus[i].r,&Bus[i].t);
        rec[++tot] = (Rec){Bus[i].l, 0, 0, i};
        rec[++tot] = (Rec){Bus[i].r, 0, 1, i};
    }
    for(int i = 1;i <= M;i++)
    {
        scanf("%d %d %d",&Peo[i].l,&Peo[i].r,&Peo[i].t);
        rec[++tot] = (Rec){Peo[i].l, 1, 0, i};
        rec[++tot] = (Rec){Peo[i].r, 1, 1, i};
    }
    sort(rec + 1,rec + tot + 1,cmpx);
    for(int i = 1, j;i <= tot;i++)
    {
        ++Index;
        for(j = i;rec[j].x == rec[i].x && j <= tot;j++);
        for(int k = i;k < j;k++)
        {
            if (rec[k].p1 == 0)
            {
                if (rec[k].p2 == 0)
                    Bus[rec[k].num].l = Index;
                else
                    Bus[rec[k].num].r = Index;
            }
            else
            {
                if (rec[k].p2 == 0)
                    Peo[rec[k].num].l = Index;
                else
                    Peo[rec[k].num].r = Index;
            }
        }
        i = j - 1;
    }
}

int cmp(Ery a,Ery b)
{
    if (a.r != b.r)
        return a.r < b.r;
    return a.p < b.p;
}

inline int lowbit(int x)
{
    return x & (-x);
}

void Ins(int x,int val,int num)
{
    Pair t;
    t = (Pair){val, num};
    while(x <= Index)
    {
        W[x].insert(t);
        x += lowbit(x);
    }
}

int Ask(int x,int val)
{
    Pair t, c;
    t = (Pair){INF, -1};
    c = (Pair){val, 0};
    while(x)
    {
        set<Pair>::iterator temp = W[x].lower_bound(c);
        if (temp != W[x].end())
        {
            if (*temp < t)
                t = *temp;
        }
        x -= lowbit(x);
    }
    return t.num;
}

void Work()
{
    tot = 0;
    for(int i = 1;i <= N;i++)
    {
        q[++tot] = (Ery){Bus[i].l, Bus[i].r, Bus[i].t, 1, i};
    }
    for(int i = 1;i <= M;i++)
    {
        q[++tot] = (Ery){Peo[i].l, Peo[i].r, Peo[i].t, 0, i};
    }
    sort(q + 1,q + tot + 1,cmp);
    for(int i = tot;i >= 1;i--)
    {
        if (q[i].p == 1)
            Ins(q[i].l, q[i].t, q[i].num);
        else
            Ans[q[i].num] = Ask(q[i].l, q[i].t);
    }
    for(int i = 1;i <= M;i++)
        printf("%d ",Ans[i]);
}

int main()
{
    Init();
    Work();
    return 0;
}