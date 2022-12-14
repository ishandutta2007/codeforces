#include <cstdio>
#include <cstring>

int n, pa;
char s[1024];
char r[1024];

int mem[1024][32][32][2];

int gen(int p, int l1, int l2, int gt)
{
    if (mem[p][l1][l2][gt] != -1)
    {
        return 0;
    }
    if (p >= n)
    {
        return gt;
    }
    if (gt)
    {
        for (int c = 0; c < pa; ++c)
        {
            if (c != l1 && c != l2)
            {
                r[p] = 'a' + c;
                if (gen(p + 1, l2, c, gt))
                {
                    return (mem[p][l1][l2][gt] = 1);
                }
            }
        }
    }
    else
    {
        for (int c = s[p] - 'a'; c < pa; ++c)
        {
            if (c != l1 && c != l2)
            {
                r[p] = 'a' + c;
                int ngt = gt;
                if (c > s[p] - 'a')
                    ngt = 1;
                if (gen(p + 1, l2, c, ngt))
                {
                    return (mem[p][l1][l2][gt] = 1);
                }
            }
        }
    }
    return (mem[p][l1][l2][gt] = 0);
}

int main()
{
    scanf("%d %d", &n, &pa);
    scanf("%s", s);

    memset(mem, -1, sizeof(mem));
    if (!gen(0, 27, 27, 0))
    {
        printf("NO\n");
    }
    else
    {
        r[n] = '\0';
        printf("%s\n", r);
    }
    return 0;
}