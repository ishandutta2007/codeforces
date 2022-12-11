#include <cstdio>
#include <cstring>
#include <stack>
static const int MAXN = 1e5 + 4;
static const int ALPHABET = 26;

int n;
char s[MAXN];
int last_occ[ALPHABET];
std::stack<char> stk;

int main()
{
    gets(s);
    n = strlen(s);
    for (int i = 0; i < ALPHABET; ++i) last_occ[i] = -1;
    for (int i = 0; i < n; ++i) last_occ[s[i] - 'a'] = i;

    int ptr = 0;
    for (int i = 0; i < ALPHABET; ++i) {
        if (i != 0) while (!stk.empty() && stk.top() <= i) {
            putchar(stk.top() + 'a'); stk.pop();
        }
        while (ptr <= last_occ[i]) {
            if (s[ptr] == i + 'a') putchar(i + 'a');
            else stk.push(s[ptr] - 'a');
            ptr++;
        }
    }
    while (!stk.empty()) { putchar(stk.top() + 'a'); stk.pop(); }
    putchar('\n');

    return 0;
}