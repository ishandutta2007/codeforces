#include <cstdio>
#include <cstdlib>

const int MAXN = 300;

struct eglist
{
    int other[MAXN * MAXN], succ[MAXN * MAXN], last[MAXN * MAXN], sum;
    void AddEdge(int a, int b)
    {
        other[++sum] = b, succ[sum] = last[a], last[a] = sum;
    }
}e;

int N, q[MAXN], t, w, d[MAXN], c[MAXN], Ans = 2000000000;

void Init()
{
    scanf("%d", &N);
    for(int i = 1;i <= N;i++)
        scanf("%d", &c[i]);
    for(int i = 1;i <= N;i++)
    {
        int k;
        scanf("%d", &k);
        for(int j = 1;j <= k;j++)
        {
            int a;
            scanf("%d", &a);
            e.AddEdge(a, i);
        }
    }
}

int st[4][MAXN], len[4];

void Work(int now)
{
    for(int i = 1;i <= N;i++)
        d[i] = 0;
    for(int i = 1;i <= N;i++)
        for(int j = e.last[i];j;j = e.succ[j])
            d[e.other[j]]++;
    t = 0, w = 0;
    len[1] = len[2] = len[3] = 0;
    for(int i = 1;i <= N;i++)
        if (d[i] == 0)
        {
            st[c[i]][++len[c[i]]] = i;
            q[++w] = i;
        }
    int res = 0, fin = 0;
    while(fin < N)
    {
        if (len[now])
        {
            int x = st[now][len[now]];
            len[now]--;
            res++;
            fin++;
            for(int j = e.last[x];j;j = e.succ[j])
            {
                int y = e.other[j];
                d[y]--;
                if (d[y] == 0)
                {
                    st[c[y]][++len[c[y]]] = y;
                }
            }
        }
        else
        {
            now = now % 3 + 1;
            res++;
        }
    }
    if (res < Ans)
        Ans = res;
}

int main()
{
 
    Init();
    for(int i = 1;i <= 3;i++)
        Work(i);
    printf("%d\n", Ans);
    return 0;
}