#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
using namespace std;

bool IsPrime(int x)
{
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

inline void Normalize(int& x, int mod)
{
    while (x >= mod) {
        x -= mod;
    }
    while (x < 0) {
        x += mod;
    }
}

inline void ModSum(int& x, int y, int mod)
{
    x += y;
    Normalize(x, mod);
}

inline int GetModSum(int x, int y, int mod)
{
    ModSum(x, y, mod);
    return x;
}

inline void ModMult(int& x, int y, int mod)
{
    x = (1LL * x * y) % mod;
    Normalize(x, mod);
}

inline int GetModMult(int x, int y, int mod)
{
    ModMult(x, y, mod);
    return x;
}

inline int GetCharIndex(char c)
{
    return c - '0' + 1;
}

inline char GetIndexChar(int index)
{
    return '0' + index - 1;
}

const int kMaxC = 10;
const int kMinC = 1;

const int kAmountOfMods = 3;
const int kMods[kAmountOfMods] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9, 
                                  1000 * 1000 * 1000 + 21};
const int kBase[kAmountOfMods] = {11, 13, 17};

struct Hash
{
    Hash() 
    {
        for (int i = 0; i < kAmountOfMods; ++i) {
            vals[i] = 0;
        }
    }

    explicit Hash(char c)
    {
        int ic = GetCharIndex(c);
        for (int i = 0; i < kAmountOfMods; ++i) {
            vals[i] = ic;
            Normalize(vals[i], kMods[i]);
        }
    }

    int vals[kAmountOfMods];
};

vector<Hash> pows;

vector<Hash> precalced[kMaxC + 1];

Hash operator * (const Hash& lhs, const Hash& rhs)
{
    Hash result(lhs);
    for (int i = 0; i < kAmountOfMods; ++i) {
        ModMult(result.vals[i], rhs.vals[i], kMods[i]);
    }
    return result;
}

void HashMult(Hash& lhs, const Hash& rhs)
{
    for (int i = 0; i < kAmountOfMods; ++i) {
        ModMult(lhs.vals[i], rhs.vals[i], kMods[i]);
    }
}

void HashSum(Hash& lhs, const Hash& rhs)
{
    for (int i = 0; i < kAmountOfMods; ++i) {
        ModSum(lhs.vals[i], rhs.vals[i], kMods[i]);
    }
}

Hash operator + (const Hash& lhs, const Hash& rhs)
{
    Hash result(lhs);
    for (int i = 0; i < kAmountOfMods; ++i) {
        ModSum(result.vals[i], rhs.vals[i], kMods[i]);
    }
    return result;
}

bool operator == (const Hash& lhs, const Hash& rhs)
{
    for (int i = 0; i < kAmountOfMods; ++i) {
        if (lhs.vals[i] != rhs.vals[i]) {
            return false;
        }
    }
    return true;
}

void Init(int n)
{
    pows.resize(n + 1);
    for (int i = 0; i < kAmountOfMods; ++i) {
        pows[0].vals[i] = 1;
        for (int j = 1; j <= n; ++j) {
            pows[j].vals[i] = pows[j - 1].vals[i];
            ModMult(pows[j].vals[i], kBase[i], kMods[i]);
        }
    }
    for (int i = kMinC; i <= kMaxC; ++i) {
        char c = GetIndexChar(i);
        precalced[i].resize(n + 1);
        precalced[i][1] = Hash(c);
        for (int j = 2; j <= n; ++j) {
            precalced[i][j] = Hash(c);
            HashMult(precalced[i][j], pows[j - 1]);
            HashSum(precalced[i][j], precalced[i][j - 1]);
        }
    }
}

const int kMaxN = 1e5;

Hash t[4 * kMaxN];
char pushed[4 * kMaxN];

char s[kMaxN + 1];

void Build(int v, int tl, int tr)
{
    pushed[v] = 0;
    if (tl == tr) {
        t[v] = Hash(s[tl]);
    } else {
        int tm = (tl + tr) >> 1;

        Build(2 * v, tl, tm);
        Build(2 * v + 1, tm + 1, tr);

        t[v] = t[2 * v + 1];
        HashMult(t[v], pows[tm - tl + 1]);
        HashSum(t[v], t[2 * v]);
    }
}

void Push(int v, int tl, int tr)
{
    if (!pushed[v]) {
        return;
    }
    if (tl == tr) {
        pushed[v] = 0;
        return;
    }
    pushed[2 * v] = pushed[2 * v + 1] = pushed[v];
    int tm = (tl + tr) >> 1;
    t[2 * v] = precalced[GetCharIndex(pushed[v])][tm - tl + 1];
    t[2 * v + 1] = precalced[GetCharIndex(pushed[v])][tr - (tm + 1) + 1];
    pushed[v] = 0;
}

Hash Get(int v, int tl, int tr, int l, int r)
{
    Push(v, tl, tr);
    if (tl == l && tr == r) {
        return t[v];
    } else {
        int tm = (tl + tr) >> 1;

        if (r <= tm) {
            return Get(2 * v, tl, tm, l, r);
        } else if (l > tm) {
            return Get(2 * v + 1, tm + 1, tr, l, r);
        } else {
            Hash result = Get(2 * v + 1, tm + 1, tr, tm + 1, r);
            HashMult(result, pows[tm - l + 1]);
            HashSum(result, Get(2 * v, tl, tm, l, tm));
            return result;
        }
    }
}

void Set(int v, int tl, int tr, int l, int r, char c)
{
    Push(v, tl, tr);
    if (tl == l && tr == r) {
        pushed[v] = c;
        t[v] = precalced[GetCharIndex(c)][tr - tl + 1];
    } else {
        int tm = (tl + tr) >> 1;

        if (r <= tm) {
            Set(2 * v, tl, tm, l, r, c);
        } else if (l > tm) {
            Set(2 * v + 1, tm + 1, tr, l, r, c);
        } else {
            Set(2 * v, tl, tm, l, tm, c);
            Set(2 * v + 1, tm + 1, tr, tm + 1, r, c);
        }

        t[v] = t[2 * v + 1];
        HashMult(t[v], pows[tm - tl + 1]);
        HashSum(t[v], t[2 * v]);
    }
}

bool Check(int l, int r, int d, int n)
{
    int all_len = r - l + 1;
    if (all_len == d) {
        return true;
    }
    int len = all_len - d;
    return Get(1, 0, n - 1, l, l + len - 1) ==
           Get(1, 0, n - 1, r - len + 1, r); 
}   

int main()
{
    /*
    int start = 1e9 + 7;
    for (int i = start; i <= start + 1000; ++i) {
        if (IsPrime(i)) {
            cout << i << endl;
        }
    }
    */

    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);

    Init(n);

    scanf("%s", s);

    Build(1, 0, n - 1);

    stringstream ans;
    for (int q = 0; q < m + k; ++q) {
        int tp;
        scanf("%d", &tp);

        if (tp == 1) {
            int l, r;
            char c;
            scanf("%d%d %c", &l, &r, &c);
            --l;
            --r;
            Set(1, 0, n - 1, l, r, c);
        } else {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            --l;
            --r;
            if (Check(l, r, d, n)) {
                ans << "YES\n";
            } else {
                ans << "NO\n";
            }
        }
    }

    puts(ans.str().c_str());

    return 0;
}