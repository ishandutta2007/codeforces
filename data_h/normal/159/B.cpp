#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 300000;
struct node
{
    int x, y;
}a[MAXN], b[MAXN], sa[MAXN], sb[MAXN];
int N, M, Ans1, Ans2, sta, stb, lena, lenb;

int cmp(node a,node b)
{
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

void Init()
{
    scanf("%d %d",&N,&M);
    for(int i = 1;i <= N;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    for(int i = 1;i <= M;i++)
        scanf("%d %d",&b[i].x,&b[i].y);
    sort(a + 1,a + N + 1,cmp);
    sort(b + 1,b + M + 1,cmp);  
}

void Get(int val)
{
    lena = lenb = 0;
    while(sta <= N && a[sta].y == val)
    {
        sa[++lena] = a[sta];
        sta++;
    }
    while(stb <= M && b[stb].y == val)
    {
        sb[++lenb] = b[stb];
        stb++;
    }
}

void Work()
{
    sta = 1, stb = 1;
    while(sta <= N && stb <= M)
    {
        Get(min(a[sta].y, b[stb].y));
        Ans1 += min(lena, lenb);
        for(int i = 1, j, k = 1, l;i <= lena;i++)
        {
            int p = sa[i].x;
            j = i;
            while(j <= lena && sa[j].x == p)
                j++;
            while(k <= lenb && sb[k].x < p)
                k++;
            if (k <= lenb && sb[k].x == p)
            {
                l = k;
                while(l <= lenb && sb[l].x == p)
                    l++;
                Ans2 += min(j - i, l - k);
                k = l - 1;
            }
            i = j - 1;
        }
    }
    printf("%d %d\n",Ans1,Ans2);
}

int main()
{
    Init();
    Work();
    return 0;
}