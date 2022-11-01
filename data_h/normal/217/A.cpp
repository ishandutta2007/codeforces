#include <cstdio>
#include <cstdlib>

const int MAXN = 200;

struct node
{
    int x, y, pos;
}p[MAXN];
int Father[MAXN];

int find(int x)
{
    int t, p = x;
    while(Father[p] != p)
        p = Father[p];
    while(x != p)
    {
        t = Father[x];
        Father[x] = p;
        x = t;
    }
    return p;
}

int main()
{

    int N;
    scanf("%d", &N);
    for(int i = 1;i <= N;i++)
        scanf("%d %d", &p[i].x, &p[i].y), p[i].pos = i, Father[i] = i;
    for(int i = 1;i <= N;i++)
        for(int j = i + 1;j <= N;j++)
        {
            int fi = find(i);
            int fj = find(j);
            if (fi == fj)
                continue;
            if (p[i].x == p[j].x || p[i].y == p[j].y)
                Father[fi] = fj;
        }
    int cnt = 0;
    for (int i = 1;i <= N;i++)
        if (Father[i] == i)
            cnt++;
    printf("%d\n", cnt - 1);
    return 0;
}