#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct state
{
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 100000;
state st[MAXLEN * 2];

int sz, last;
void sa_init()
{
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;

    for (int i = 0; i < MAXLEN * 2; ++i)
        st[i].next.clear();
}

void sa_extend(char c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else
    {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else
        {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p != -1 && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

long long n;
int m;
char t[1 << 20];

int term[MAXLEN * 2][4];

int getTerm(int node, int tar)
{
    if (term[node][tar] != -1)
        return term[node][tar];
    if (!st[node].next.count('A' + tar))
    {
        return (term[node][tar] = 1);
    }
    for (char x = 'A'; x <= 'D'; ++x)
    {
        if (st[node].next.count(x))
        {
            if (term[node][tar] == -1)
                term[node][tar] = 1 + getTerm(st[node].next[x], tar);
            else
                term[node][tar] = min(term[node][tar], 1 + getTerm(st[node].next[x], tar));
        }
    }
    return term[node][tar];
}

int bs[4][4];
long long bsol = -1;

int dp[1 << 20][5];

int getDP(int ln, int x)
{
    if (ln <= 0)
        return 0;
    if (dp[ln][x] != -1)
        return dp[ln][x];
    if (x == 4)
    {
        for (int y = 0; y < 4; ++y)
        {
            dp[ln][x] = max(dp[ln][x], getDP(ln, y));
        }
    }
    else
    {
        for (int y = 0; y < 4; ++y)
        {
            dp[ln][x] = max(dp[ln][x], 1 + getDP(ln - bs[x][y], y));
        }
    }
    return dp[ln][x];
}

bool us[4];

void loop(int cnt, int len, int beg, int prev)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!us[i])
        {
            us[i] = 1;
            loop(cnt + 1, len + bs[prev][i], beg, i);
            us[i] = 0;
        }
        else if (i == beg)
        {
            int alen = len + bs[prev][i];
            bsol = max(bsol, n / alen * cnt + getDP(n % alen, i));
            if (n >= alen)
            {
                bsol = max(bsol, (n - alen) / alen * cnt + getDP(n % alen + alen, i));
            }
        }
    }
}

int main()
{
    scanf("%lld", &n);
    scanf("%s", t);

    sa_init();
    m = strlen(t);
    for (int i = 0; i < m; ++i)
        sa_extend(t[i]);

    memset(term, -1, sizeof(term));
    memset(bs, -1, sizeof(bs));
    for (int i = 0; i < 4; ++i)
    {
        int n1 = st[0].next['A' + i];
        for (int j = 0; j < 4; ++j)
        {
            bs[i][j] = getTerm(n1, j);
            // printf("%c %c : %d\n", 'A' + i, 'A' + j, bs[i][j]);
        }
    }

    memset(us, 0, sizeof(us));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 4; ++i)
    {
        memset(us, 0, sizeof(us));
        us[i] = 1;
        loop(1, 0, i, i);
    }
    if (n < (1 << 19))
    {
        bsol = getDP(n, 4);
    }
    printf("%lld\n", bsol);
    return 0;
}