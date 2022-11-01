#include <cstdio>
#include <cstdlib>

const int MAXN = 3100000;

int w[MAXN * 10];
int L[6000], R[6000], M, N, F[MAXN];
char str[MAXN], ans[MAXN];

inline void Build(int rt, int l, int r)
{
    w[rt] = r - l + 1;
    if (l >= r)
        return ;
    int mid = (l + r) >> 1;
    Build(rt << 1, l, mid);
    Build((rt << 1) + 1, mid + 1, r);
}

void Init()
{
    scanf("%s", str + 1);
    scanf("%d %d", &M, &N);
    for(int i = 1;i <= N;i++)
        scanf("%d %d", &L[i], &R[i]);
    Build(1, 1, M);
}

inline int Find(int rt, int l, int r, int rank)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (rank > w[rt * 2])
        return Find((rt << 1) + 1, ((l + r) >> 1) + 1, r, rank - w[rt * 2]);
    return Find(rt << 1, l, ((l + r) >> 1), rank);
}

inline void Delete(int rt, int l, int r, int pos)
{
    if (l <= pos && pos <= r)
    {
        w[rt]--;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        if (pos > mid)
            Delete((rt << 1) + 1, ((l + r) >> 1) + 1, r, pos);
        else
            Delete(rt << 1, l, ((l + r) >> 1), pos);
    }
}

inline void Work()
{
    for(int i = N;i >= 1;i--)
    if (R[i] < w[1])
    {
        int len = R[i] - L[i] + 1;
        int now = L[i] + 1;
        if (now > R[i])
            now = L[i];
        for(int j = 1;j <= len && R[i] < w[1];j++)
        {
            int k = Find(1, 1, M, R[i] + 1);
            Delete(1, 1, M, k);
            F[k] = Find(1, 1, M, now);
            now += 2;
            if (now > R[i])
                now = L[i];
        }
    }
    for(int i = 1, j = 1;i <= M;i++)
    if (F[i])
        ans[i] = ans[F[i]];
    else
        ans[i] = str[j++];
    printf("%s\n", ans + 1);
}

int main()
{

    Init();
    Work();
    return 0;
}