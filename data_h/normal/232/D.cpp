#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 210000, inf = 2000000000;
const int debug = 0;
int a[MAXN], s[MAXN], N, len;
struct Rec
{
    int val, pos;
}rec[MAXN];

int bx[MAXN], by[MAXN], buc[MAXN], rank[MAXN], sa[MAXN], h[MAXN];
int R[21][MAXN], mi[MAXN];

int cmp(Rec a, Rec b)
{
    return a.val < b.val;
}

void Simple(int a[], int len)
{
    for(int i = 1;i <= len;i++)
        rec[i] = (Rec){a[i], i};
    sort(rec + 1, rec + len + 1, cmp);
    int MaxNum = 0;
    for(int i = 1;i <= len;)
    {
        int it = rec[i].val;
        ++MaxNum;
        while(rec[i].val == it)
        {
            a[rec[i].pos] = MaxNum;
            i++;
        }
    }
}

int cmp(int r[], int i, int j, int k)
{
    return r[i] == r[j] && r[i + k] == r[j + k];
}

void Array_Suffix(int s[], int len)
{
    int *x = bx, *y = by, p = len;
    for(int i = 0;i <= len;i++) buc[i] = 0;
    for(int i = 1;i <= len;i++) buc[x[i] = s[i]]++;
    for(int i = 0;i <= len;i++) buc[i] += buc[i - 1];
    for(int i = len;i >= 1;i--) sa[buc[x[i]]--] = i;
    for(int k = 1;k <= len;k *= 2)
    {
        p = 0;
        for(int i = len - k + 1;i <= len;i++) y[++p] = i;
        for(int i = 1;i <= len;i++) if (sa[i] - k > 0) y[++p] = sa[i] - k;
        for(int i = 0;i <= len;i++) buc[i] = 0;
        for(int i = 1;i <= len;i++) buc[x[y[i]]]++;
        for(int i = 1;i <= len;i++) buc[i] += buc[i - 1];
        for(int i = len;i >= 1;i--) sa[buc[x[y[i]]]--] = y[i];
        swap(x, y);
        x[sa[1]] = p = 1;
        for(int i = 2;i <= len;i++)
            if (cmp(y, sa[i - 1], sa[i], k))
                x[sa[i]] = p;
            else
                x[sa[i]] = ++p;
    }
    for(int i = 1;i <= len;i++)
        rank[sa[i]] = i;
    
    int k = 0;
    for(int i = 1;i <= len;i++)
    {
        if (k) k--;
        if (rank[i] == 1)
            continue;
        int j = sa[rank[i] - 1];
        while(i + k <= len && j + k <= len && s[i + k] == s[j + k])
            k++;
        h[rank[i]] = k;
    }
    
    if (debug)
    {
        for(int i = 1;i <= len;i++)
        {
            int tmp = sa[i];
            for(int j = tmp;j <= len;j++)
                printf("%d ", s[j]);
            printf("   h : %d\n", h[i]);
        }
    }
}

void MakeRMQ(int h[], int len)
{
    for(int i = 1;i <= len;i++)
        R[0][i] = h[i];
    mi[0] = 1;
    int cnt = 0;
    for(int i = 1;i <= len;i++)
    {
        if (i >= (1 << (cnt + 1)))
            cnt++;
        mi[i] = cnt;
    }
    for(int i = 1;i <= 20;i++)
        for(int j = 1;j <= len;j++)
        {
            R[i][j] = R[i - 1][j];
            if (j + (1 << (i - 1)) <= len)
                R[i][j] = min(R[i][j], R[i - 1][j + (1 << (i - 1))]);
        }
}

int AskMin(int l, int r)
{
    l++;
    if (l > r)
        return inf;
    int tmp = mi[r - l + 1];
    return min(R[tmp][l], R[tmp][r - (1 << tmp) + 1]);
}

struct node
{
    int pos, vl, vr, type1, type2;
    
}rv[MAXN * 4];
int tot, ans[MAXN], T[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

inline int ins(int pos)
{
    for(int i = pos;i <= len;i += lowbit(i))
        T[i]++;
}

inline int ask(int pos)
{
    int res = 0;
    for(int i = pos;i;i -= lowbit(i))
        res += T[i];
    return res;
}

int cmpl(node a, node b)
{
    return a.vl < b.vl;
}

int cmpr(node a, node b)
{
    return a.vr < b.vr;
}

void Work()
{
    int Q, l, r;
    scanf("%d", &Q);
    tot = 0;
    for(int i = 1;i <= Q;i++)
    {
        scanf("%d %d", &l, &r);
        if (l == r)
        {
            ans[i] = N - 1;
            continue;
        }
        r--;
        int ans = 0, length = (r - l + 1);
        int ll, rr, mid, L, R;
        ll = rank[l], rr = len;
        while(ll < rr)
        {
            mid = (ll + rr) / 2 + 1;
            if (AskMin(rank[l], mid) >= length)
                ll = mid;
            else
                rr = mid - 1;
        }
        R = ll;
        ll = 1, rr = rank[l];
        while(ll < rr)
        {
            mid = (ll + rr) / 2;
            if (AskMin(mid, rank[l]) >= length)
                rr = mid;
            else
                ll = mid + 1;
        }
        L = ll;
        if (debug)
            printf("L : %d  Mid : %d  R : %d\n", L, rank[l], R);
        //printf("%d\n", sum[R] - sum[L - 1]);
        // N ~ N - 2
        //find(L, R, N - 1 < sa[i] <= l + (N - 1) - length - 1) + find(L, R, r + (N - 1) + 1 < sa[i] <= len)
        if (N <= l + (N - 1) - length - 1)
        {
            rv[++tot] = (node){R, N - 1, l + (N - 1) - length - 1, i, 1};
            rv[++tot] = (node){L - 1, N - 1, l + (N - 1) - length - 1, i, -1};
        }
        if (r + (N - 1) + 2 <= len)
        {
            rv[++tot] = (node){R, r + (N - 1) + 1, len, i, 1};
            rv[++tot] = (node){L - 1, r + (N - 1) + 1, len, i, -1};
        }
    }
    sort(rv + 1, rv + tot + 1, cmpl);
    memset(T, 0, sizeof(T));
    int j;
    j = 1;
    for(int i = 1;i <= len;i++)
    {
        int pos = rank[i];
        ins(pos);
        while(j <= tot && rv[j].vl == i)
        {
            ans[rv[j].type1] -= rv[j].type2 * ask(rv[j].pos);
            j++;
        }
    }
    
    sort(rv + 1, rv + tot + 1, cmpr);
    memset(T, 0, sizeof(T));
    j = 1;
    for(int i = 1;i <= len;i++)
    {
        int pos = rank[i];
        ins(pos);
        while(j <= tot && rv[j].vr == i)
        {
            ans[rv[j].type1] += rv[j].type2 * ask(rv[j].pos);
            j++;
        }
    }
    for(int i = 1;i <= Q;i++)
        printf("%d\n", ans[i]);
}

int main()
{

    scanf("%d", &N);
    len = 0;
    for(int i = 1;i <= N;i++)
        scanf("%d", &a[i]);
    for(int i = 2;i <= N;i++)
        s[++len] = a[i] - a[i - 1];
    for(int i = 2;i <= N;i++)
        s[++len] = -(a[i] - a[i - 1]);
    
    if (debug)
    {
        printf("s is:\n");
        for(int i = 1;i <= len;i++)
            printf("%d ", s[i]);
        printf("\n");
    }
    Simple(s, len);
    
    if (debug)
    {
        printf("s is:\n");
        for(int i = 1;i <= len;i++)
            printf("%d ", s[i]);
        printf("\n");
    }
    
    Array_Suffix(s, len);
    MakeRMQ(h, len);
    Work();
    return 0;
}