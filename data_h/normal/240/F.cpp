#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200000;
struct node
{
    int cnt[26];
    int lazy, l, r;
    void clear()
    {
        memset(cnt, 0, sizeof(cnt));
        lazy = -1;
    }
}T[MAXN * 4];

int N, M;
char str[MAXN];

FILE *fin, *fout;


void update(node &a, node &b, node &c)
{
    for(int i = 0;i < 26;i++)
        a.cnt[i] = b.cnt[i] + c.cnt[i];
}

void push(node &a, node &b, node &c)
{
    if (a.lazy != -1)
    {
        int tmp = a.lazy;
        a.lazy = -1;
        for(int i = 0;i < 26;i++)
            b.cnt[i] = c.cnt[i] = 0;
        b.cnt[tmp] = b.r - b.l + 1; b.lazy = tmp;
        c.cnt[tmp] = c.r - c.l + 1; c.lazy = tmp;
    }
}

void Build(int rt, int l, int r, char buf[])
{
    T[rt].clear();
    T[rt].l = l; 
    T[rt].r = r;
    if (l == r)
    {
        T[rt].cnt[buf[l] - 'a']++;
        T[rt].lazy = buf[l] - 'a';
        return;
    }
    int mid = (l + r) / 2;
    Build(rt * 2, l, mid, buf);
    Build(rt * 2 + 1, mid + 1, r, buf);
    update(T[rt], T[rt * 2], T[rt * 2 + 1]);
}

void makeSame(int rt, int l, int r, int val)
{
    if (T[rt].l == l && r == T[rt].r)
    {
        T[rt].lazy = val;
        for(int i = 0;i < 26;i++)
            T[rt].cnt[i] = 0;
        T[rt].cnt[val] = T[rt].r - T[rt].l + 1;
        return;
    }
    push(T[rt], T[rt * 2], T[rt * 2 + 1]);
    int mid = (T[rt].l + T[rt].r) / 2;
    if (r <= mid)
        makeSame(rt * 2, l, r, val);
    else
    if (l > mid)
        makeSame(rt * 2 + 1, l, r, val);
    else
    {
        makeSame(rt * 2, l, mid, val);
        makeSame(rt * 2 + 1, mid + 1, r, val);
    }
    update(T[rt], T[rt * 2], T[rt * 2 + 1]);

}

void Init()
{
    fscanf(fin, "%d %d\n", &N, &M);
    fscanf(fin, "%s", str + 1);
}

void Ask(int rt, int l, int r, int bak[])
{
    if (T[rt].l == l && r == T[rt].r)
    {
        for(int i = 0;i < 26;i++)
            bak[i] += T[rt].cnt[i];
        return;
    }
    push(T[rt], T[rt * 2], T[rt * 2 + 1]);
    int mid = (T[rt].l + T[rt].r) / 2;
    if (r <= mid)
        Ask(rt * 2, l, r, bak);
    else
    if (l > mid)
        Ask(rt * 2 + 1, l, r, bak);
    else
    {
        Ask(rt * 2, l, mid, bak);
        Ask(rt * 2 + 1, mid + 1, r, bak);
    }
    update(T[rt], T[rt * 2], T[rt * 2 + 1]);
}

void Doit(int l, int r)
{
    int bak[26] = {0};
    Ask(1, l, r, bak);
    int oddCnt = 0, who = -1, tot = 0;
    for(int i = 0;i < 26;i++)
    {
        tot += bak[i];
        if (bak[i] % 2 == 1)
            who = i, oddCnt++;
    }
    if (oddCnt != tot % 2)
        return;
    if (oddCnt)
        bak[who]--;
    int sum;
    sum = 0;
    for(int i = 0;i < 26;i++)
    if (bak[i])
    {
        int tmp = bak[i] / 2;
        makeSame(1, l + sum, l + sum + tmp - 1, i);
        sum += tmp;
    }
    sum = 0;
    for(int i = 0;i < 26;i++)
    if (bak[i])
    {
        int tmp = bak[i] / 2;
        makeSame(1, r - sum - tmp + 1, r - sum, i);
        sum += tmp;
    }
    if (oddCnt)
    {
        makeSame(1, r - sum, r - sum, who);
    }
}


void Work()
{
    for(int i = 1;i <= M;i++)
    {
        int l, r;
        fscanf(fin, "%d %d", &l, &r);
        Doit(l, r);
        //printf("ok %d %d\n", l, r);
    }
}

void Print(int rt)
{
    if (T[rt].l == T[rt].r)
    {
        fprintf(fout, "%c", T[rt].lazy + 'a');
    }
    else
    {
        push(T[rt], T[rt * 2], T[rt * 2 + 1]);
        Print(rt * 2);
        Print(rt * 2 + 1);
    }
}

int main()
{
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    Init();
    Build(1, 1, N, str);
    Work();
    Print(1);
    printf("\n");
    //system("pause");
    return 0;
}