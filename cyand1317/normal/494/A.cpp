#include <cstdio>
static const int MAXN = 1e5 + 3;

int n;
char s[MAXN];
int ans[MAXN], ans_top = 0;

int main()
{
    for (n = 0; (s[n] = getchar()) != '\n'; ++n) ;

    int par_val = 0;
    for (int i = 0; i < n; ++i) switch (s[i]) {
        case '(': ++par_val; break;
        case ')': if (--par_val < 0) { puts("-1"); return 0; } break;
        case '#':
            if (par_val <= 0) { puts("-1"); return 0; }
            ans[ans_top++] = 1; --par_val;
            break;
        default: puts("> <");
    }

    ans[ans_top - 1] += par_val;

    // Validation
    ans_top = par_val = 0;
    for (int i = 0; i < n; ++i) switch (s[i]) {
        case '(': ++par_val; break;
        case ')': if (--par_val < 0) { puts("-1"); return 0; } break;
        case '#': if ((par_val -= ans[ans_top++]) < 0) { puts("-1"); return 0; } break;
    }
    for (int i = 0; i < ans_top; ++i) printf("%d\n", ans[i]);

    return 0;
}