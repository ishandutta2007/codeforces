#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000;
const long long INF = 200000000000000ll;
struct node
{
    int c, size, num;
}d[MAXN];

int N, pos[2][MAXN], Index, st[MAXN], p1, p2, e[MAXN], tot;
long long Len[2][MAXN], sum = 0, Ans = -INF;

int cmp(node a,node b)
{
    if (a.c != b.c)
        return a.c < b.c;
    return a.size > b.size;
}

void Init()
{
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)
    {
        scanf("%d %d",&d[i].c,&d[i].size);
        d[i].num = i;
        Len[0][i] = Len[1][i] = -INF;
    }
    sort(d + 1,d + N + 1,cmp);
    for(int i = 1, j;i <= N;i++)
    {
        ++Index; sum = 0;
        st[Index] = i;
        j = i;
        while(j <= N && d[j].c == d[i].c)
            j++;
        for(int k = i;k < j;k++)
        {
            int p = k - i + 1;
            sum += d[k].size;
            d[k].c = Index;
            if (sum > Len[0][p])
            {
                Len[1][p] = Len[0][p];
                pos[1][p] = pos[0][p];
                
                Len[0][p] = sum;
                pos[0][p] = Index;
            }
            else
            if (sum > Len[1][p])
            {
                Len[1][p] = sum;
                pos[1][p] = Index;
            }
        }
        i = j - 1;
    }
    for(int i = 1;i <= N;i++)
    {
        if (Len[0][i] + Len[1][i] > Ans)
            Ans = Len[0][i] + Len[1][i], p1 = pos[0][i], p2 = pos[1][i];
        if (pos[0][i] == pos[0][i + 1])
        {
            if (Len[0][i] + Len[1][i + 1] > Ans)
                Ans = Len[0][i] + Len[1][i + 1], p1 = pos[0][i], p2 = pos[1][i + 1];
            if (Len[1][i] + Len[0][i + 1] > Ans)
                Ans = Len[1][i] + Len[0][i + 1], p1 = pos[1][i], p2 = pos[0][i + 1];
        }
        else
        if (Len[0][i] + Len[0][i + 1] > Ans)
        {
            Ans = Len[0][i] + Len[0][i + 1], p1 = pos[0][i], p2 = pos[0][i + 1];
        }
    }
    printf("%I64d\n",Ans);
    int p = p2;
    while(1)
    {
        if (d[st[p]].c != p)
            break;
        e[++tot] = d[st[p]].num;
        st[p]++;
        p = p1 + p2 - p;
    }
    printf("%d\n",tot);
    for(int i = 1;i <= tot;i++)
        printf("%d ",e[i]);
}

int main()
{
    Init();
    return 0;
}