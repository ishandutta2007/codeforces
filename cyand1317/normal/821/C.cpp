#include <cstdio>
static const int MAXN = 3e5 + 4;

int n;
int p[MAXN];
int s[MAXN], top = 0;

int main()
{
    scanf("%d", &n);

    char op[24];
    int x, id = 0, ans = 0;
    int shuffle_top = -1;
    for (int i = 0; i < n * 2; ++i) {
        scanf("%s", op);
        if (op[0] == 'a') {
            scanf("%d", &x); --x;
            s[top] = x;
            p[x] = top++;
        } else {
            if (p[id] == top - 1) {
            } else if (p[id] == -1 && top <= shuffle_top) {
                --shuffle_top;
            } else {
                ++ans;
                for (int i = top - 1; i >= 0 && p[s[i]] != -1; --i)
                    p[s[i]] = -1;
                shuffle_top = top - 1;
            }
            --top;
            ++id;
        }
    }

    printf("%d\n", ans);
    return 0;
}