#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000787;

int sum(int a, int b) {
  a += b;
  if (a < 0) {
    return a + mod;
  }
  if (a >= mod) {
    return a - mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = (ll) r * a % mod;
    }
    a = (ll) a * a % mod;
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return (ll) a * pw(b, mod - 2) % mod;
}

const int N = (int) 4e5 + 7;
int d;
int n;
string s;
int first[N];
int aib[N];
int p26[N];
int i26[N];
int len;
vector<int> stats;
string t;

void add(int i, int x)
{
    while (i <= n)
    {
        aib[i] = sum(aib[i], x);
        i += i & (-i);
    }
}

int get(int i)
{
    int sol = 0;
    while (i)
    {
        sol = sum(sol, aib[i]);
        i -= i & (-i);
    }
    return sol;
}

int get1(int l, int r)
{
    return mul(sum(first[r], -first[l - 1]), i26[l - 1]);
}

int get2(int l, int r)
{
    l = n + 1 - l;
    r = n + 1 - r;
    swap(l, r);
    return mul(sum(get(r), -get(l - 1)), i26[l - 1]);
}

void pop()
{
    int it = sum(0, -mul(p26[n - len + 1], t.back() - 'a'));
    add(n - len + 1, it);
    t.pop_back();
    len--;
    stats.pop_back();
}

void add(char ch)
{
    t.push_back(ch);
    len++;
    first[len] = sum(first[len - 1], mul(p26[len], ch - 'a'));
    add(n - len + 1, mul(p26[n - len + 1], ch - 'a'));
    bool ok = stats.back();
    if (len >= d && get1(len - d + 1, len) == get2(len - d + 1, len))
    {
        ok = 0;
    }
    if (len >= d + 1 && get1(len - d, len) == get2(len - d, len))
    {
        ok = 0;
    }
    stats.push_back(ok);
}

bool ok()
{
    return stats.back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> s;
    n = (int) s.size();
    stats.push_back(1);
    p26[0] = 1;
    for (int i = 1; i < N; i++)
    {
        p26[i] = mul(p26[i - 1], 26);
    }
    i26[N - 1] = dv(p26[0], p26[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        i26[i] = mul(i26[i + 1], 26);
    }
    int last_good = -1;
    for (int pre = 0; pre < n; pre++)
    {
        if (ok() == 0)
        {
            break;
        }
        for (char ch = s[pre] + 1; ch <= 'z'; ch++)
        {
            add(ch);
            if (ok())
            {
                last_good = pre;
            }
            pop();
        }
        add(s[pre]);
    }
    if (last_good == -1)
    {
        cout << "Impossible\n";
        return 0;
    }
    int pre = last_good;
    while ((int) t.size() > pre)
    {
        pop();
    }
    for (char ch = s[pre] + 1; ch <= 'z'; ch++)
    {
        add(ch);
        if (ok())
        {
            break;
        }
        pop();
    }
    while ((int) t.size() < n)
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            add(ch);
            if (ok())
            {
                break;
            }
            pop();
        }
    }
    cout << t << "\n";
    return 0;
}