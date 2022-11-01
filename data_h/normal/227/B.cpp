#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

struct node
{
    int val, pos;
}p[MAXN];
int q[MAXN];
int N, M;
long long ans1, ans2;

int cmp1(node a, node b)
{
    return a.val < b.val || a.val == b.val && a.pos < b.pos;
}

int cmp2(node a, node b)
{
    return a.val < b.val || a.val == b.val && a.pos > b.pos;
}

int main()
{

    scanf("%d", &N);
    for(int i = 1;i <= N;i++)
    {
        scanf("%d", &p[i].val);
        p[i].pos = i;
    }
    scanf("%d", &M);
    for(int i = 1;i <= M;i++)
        scanf("%d", &q[i]);
    sort(p + 1, p + N + 1, cmp1);
    sort(q + 1, q + M + 1);
    for(int i = 1, j = 1;i <= M;i++)
    {
        while(p[j].val < q[i] && j <= N)
            j++;
        if (p[j].val == q[i])
            ans1 += p[j].pos;
        else
            ans1 += N;
    }
    sort(p + 1, p + N + 1, cmp2);
    for(int i = 1, j = 1;i <= M;i++)
    {
        while(p[j].val < q[i] && j <= N)
            j++;
        if (p[j].val == q[i])
            ans2 += N - p[j].pos + 1;
        else
            ans2 += N;
    }
    printf("%I64d %I64d\n", ans1, ans2);
    return 0;
}