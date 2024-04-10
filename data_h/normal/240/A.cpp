#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 200;

int M, K, hash[MAXN], N;
struct node
{
    char name[MAXN];
    int ML, MR;
}movie[MAXN];

void Init()
{
    memset(hash, 0, sizeof(hash));
    scanf("%d %d", &M, &K);
    for(int i = 1;i <= K;i++)
    {
        int tmp;
        scanf("%d", &tmp);
        hash[tmp] = 1;
    }
}

void Work()
{
    int MaxL = -1, MaxR = -1, cL = -1, cR = -1;
    scanf("%d", &N);
    for(int i = 1;i <= N;i++)
    {
        scanf("\n");
        gets(movie[i].name + 1);
        int d, a, cnt = 0, bak = 0, op1 = K, op2 = M - K;
        scanf("%d", &d);
        movie[i].ML = movie[i].MR = 0;
        for(int j = 1;j <= d;j++)
        {
            scanf("%d", &a);
            if (a == 0)
                cnt++;
            else
            if (hash[a])
                bak++, op1--;
            else
                op2--;
        }
        movie[i].ML = bak;
        if (cnt > op2)
            movie[i].ML += cnt - op2;
        movie[i].MR = bak + min(cnt, op1);
        if (MaxL < movie[i].ML)
            cL = MaxL, MaxL = movie[i].ML;
        else
        if (cL < movie[i].ML)
            cL = movie[i].ML;
            
        if (MaxR < movie[i].MR)
            cR = MaxR, MaxR = movie[i].MR;
        else
        if (cR < movie[i].MR)
            cR = movie[i].MR;
    }

    for(int i = 1;i <= N;i++)
    {
        int flag = 0;
        for(int j = 1;j <= N;j++)
            if (i != j)
            {
                if (movie[j].MR > movie[i].ML && flag == 0)
                    flag = 2;
                if (movie[j].ML > movie[i].MR)
                    flag = 1;
            }
        printf("%d\n", flag);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Work();
    return 0;
}