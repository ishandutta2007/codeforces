#include <cstdio>
#include <cstring>

int h[1 << 20];
int ps[ 1 << 20 ];
int st;
int n, q;

int main()
{
    st = 0;
    scanf("%d %d", &n, &q);
    ps[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        ps[i] = ps[i - 1] + 1;
    }
    bool flip = 0;

    int* pb = ps + 1;
    for (int i = 0; i < q; ++i)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int p;
            scanf("%d", &p);
            pb[-1] = 0;
            if (p + p <= n && !flip)
            {
                int s = p + p - 1;
                for (int j = p + p - 1; j > 0; --j)
                {
                    pb[j] = pb[j] - pb[j - 1];
                }
                for (int j = 0; j < p; ++j)
                {
                    pb[s - j] += pb[j];
                }
                pb += p;
                for (int j = 1; j < p; ++j)
                    pb[j] += pb[j - 1];
                n -= p;
            }
            else if (p + p > n && !flip)
            {
                int q = n - p;
                int s = p + p - 1;
                for (int j = n - 1; j >= n - q - q; --j)
                    pb[j] = pb[j] - pb[j - 1];
                for (int j = n - q - q; j < p; ++j)
                    pb[j] += pb[s - j];
                flip = true;
                for (int j = n - q - q; j < p; ++j)
                    pb[j] += pb[j - 1];
                n = p;
            }
            else if (p + p <= n && flip)
            {
                int q = n - p;
                int s = q + q - 1;
                for (int j = n - 1; j >= n - p - p; --j)
                    pb[j] -= pb[j - 1];
                for (int j = n - p - p; j < q; ++j)
                    pb[j] += pb[s - j];
                flip = true;
                for (int j = n - p - p; j < q; ++j)
                    pb[j] += pb[j - 1];
                n = q;
            }
            else if (p + p > n && flip)
            {
                int q = n - p;
                int s = q + q - 1;

                for (int j = q + q - 1; j > 0; --j)
                    pb[j] -= pb[j - 1];
                for (int j = 0; j < q; ++j)
                    pb[s - j] += pb[j];
                pb += q;
                for (int j = 1; j < q; ++j)
                    pb[j] += pb[j - 1];
                flip = false;
                n -= q;
            }
        }
        else
        {
            int l, r;
            scanf("%d %d", &l, &r);
            pb[-1] = 0;
            if (flip)
            {
                printf("%d\n", pb[n - l - 1] - pb[n - r - 1]);
            }
            else
            {
                printf("%d\n", pb[r - 1] - pb[l - 1]);
            }
        }
        // printf("OP OP %d %d!\n", i, flip);
        // printf("%d\n", n);
        // for (int j = 0; j < n; ++j)
        //     printf("%d ", pb[j]);
        // printf("\n");
    }
    return 0;
}