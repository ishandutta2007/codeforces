#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

struct quer
{
    int w, pos;
    long long ans;
}q[MAXN];

int a[MAXN], N, M, Q;
long long sum[MAXN];

inline int cmpv(int a, int b)
{
    return a > b;
}

inline int cmpw(quer a, quer b)
{
    return a.w < b.w;
}

inline int cmppos(quer a, quer b)
{
    return a.pos < b.pos;
}

int main()
{

    scanf("%d", &N);
    for(int i = 1;i <= N;i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + N + 1, cmpv);
    for(int i = 1;i <= N;i++)
        sum[i] = sum[i - 1] + a[i];
    scanf("%d", &Q);
    for(int i = 1;i <= Q;i++)
        scanf("%d", &q[i].w), q[i].pos = i;
    sort(q + 1, q + Q + 1, cmpw);
    for(int i = 1;i <= Q;i++)
    {
        if (i != 1 && q[i].w == q[i - 1].w)
        {
            q[i].ans = q[i - 1].ans;
            continue;
        }
        q[i].ans = 0;
        long long tmp = q[i].w;
        for(long long j = 2, dep = 1;j <= N;j += tmp, dep++, tmp = tmp * q[i].w)
        {
            long long l = j, r = min(j + tmp - 1, (long long)N);
            q[i].ans += dep * (sum[r] - sum[l - 1]);
            
        }
    }
    sort(q + 1, q + Q + 1, cmppos);
    for(int i = 1;i <= Q;i++)
        printf("%I64d ", q[i].ans);
    printf("\n");
    return 0;
}