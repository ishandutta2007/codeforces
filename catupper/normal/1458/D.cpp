#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, char> P;

char str[550000];
int cnt[1100000];
char tmp[550000];
bool alone[550000];

void go(vector<char> &tmp)
{
    int level = 550000;
    int n = tmp.size();
    int top = level, bottom = level;
    for (int i = 0; i < n; i++) {
        int nl = level;
        if (tmp[i] == '0')
            nl--;
        else
            nl++;
        int l = min(level, nl);
        cnt[l]++;
        level = nl;
        bottom = min(bottom, level);
        top = max(top, level);
    }

    for (int i = 550000; i > bottom; i--) {
        cnt[i - 1]--;
        putchar('0');
    }
    for (int i = bottom; i < top; i++) {
        if (i >= level)
            cnt[i]--;
        for (int j = 0; j < cnt[i]; j++) {
            putchar('1' - (j % 2));
        }
    }
    for (int i = top; i > level; i--) {
        putchar('0');
    }
    for (int i = bottom; i <= top; i++)
        cnt[i] = 0;

    tmp.clear();
}

void solve()
{
    scanf("%s", str);
    int n = strlen(str);
    int level = 550000;
    int bottom = level, top = level;
    for (int i = 0; i < n; i++) {
        int next_level = level;
        if (str[i] == '0')
            next_level--;
        else
            next_level++;
        int l = min(level, next_level);
        cnt[l]++;
        level = next_level;
        bottom = min(level, bottom);
        top = max(level, top);
    }

    level = 550000;
    for (int i = 0; i < n; i++) {
        int next_level = level;
        if (str[i] == '0')
            next_level--;
        else
            next_level++;
        int l = min(level, next_level);
        if (cnt[l] == 1)
            alone[i] = true;
        level = next_level;
    }
    for (int i = bottom; i <= top + 1; i++)
        cnt[i] = 0;

    level = 550000;
    int last = 0;
    vector<char> tmp;
    for (int i = 0; i < n; i++) {
        if (alone[i]) {
            go(tmp);
            putchar(str[i]);
        }
        else {
            tmp.push_back(str[i]);
        }
        alone[i] = false;
    }
    go(tmp);
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}