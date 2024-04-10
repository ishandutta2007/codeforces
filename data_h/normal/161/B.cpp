#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2000;
struct node
{
    int v, num;
}p1[MAXN], p2[MAXN];
int len1, len2, N, K, father[MAXN], v[MAXN], d[MAXN], sta[MAXN];
double Ans = 0;
struct fetch
{
    int y;
    fetch *next;
}*e[MAXN];

void Init()
{
    scanf("%d %d",&N,&K);
    for(int i = 1;i <= N;i++)
    {
        int c, t;
        scanf("%d %d",&c,&t);
        if (t == 1)
            p1[++len1] = (node){c, i};
        else
            p2[++len2] = (node){c, i};
        v[i] = c;
        sta[i] = t;
    }
}

void Link(int x,int y)
{
    fetch *Tmp = e[x];
    e[x] = new(fetch);
    e[x]->y = y;
    e[x]->next = Tmp;
}

int cmp(node a,node b)
{
    return a.v > b.v;
}

int top = 0;

void Work()
{
    sort(p1 + 1,p1 + len1 + 1,cmp);
    for(int i = 1;i <= len1 && i <= K;i++)
    {
        ++top;
        Link(top, p1[i].num);
    }
    if (len1 > K)
    {
        for(int i = K + 1;i <= len1;i++)
            Link(top, p1[i].num);
    }
    int s = 1;
    while(top < K)
    {
        top++;
        Link(top, p2[s].num);
        s++;
    }
    for(int i = s;i <= len2;i++)
        Link(top, p2[i].num);
    for(int i = 1;i <= K;i++)
    {
        int flag = 0;
        double res = 0, Min = 20000008000.0;
        for(fetch *Tmp = e[i];Tmp != NULL;Tmp = Tmp->next)
        {
            d[i]++;
            int y = Tmp->y;
            res += v[y];
            if (v[y] < Min)
                Min = v[y];
            if (sta[y] == 1)
                flag = 1;
        }
        if (flag)
            Ans += res - Min / 2.0;
        else
            Ans += res;
    }
    printf("%.1lf\n",Ans);
    for(int i = 1;i <= K;i++)
    {
        printf("%d",d[i]);
        for(fetch *Tmp = e[i];Tmp != NULL;Tmp = Tmp->next)
            printf(" %d",Tmp->y);
        printf("\n");
    }
}

int main()
{
    Init();
    Work();
    return 0;
}