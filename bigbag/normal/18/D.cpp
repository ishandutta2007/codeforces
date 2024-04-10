#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_x = 111, max_l = 2000;

struct very_long
{
    int len;
    char digit[max_l];
    very_long cpy ()
    {
        very_long a;
        a.len = len;
        for (int i = 0; i < len; i++)
            a.digit[i] = digit[i];
        return a;
    }
    void operator = (very_long a)
    {
        len = a.len;
        for (int i = 0; i < a.len; i++)
            digit[i] = a.digit[i];
    }
    void operator = (int a)
    {
        len = 0;
        if (a == 0)
        {
            len = 1;
            digit[0] = 0;
        }
        while (a != 0)
        {
            digit[len] = a % 10;
            len++;
            a /= 10;
        }
    }
    bool operator == (very_long a)
    {
        if (len != a.len) return false;
        for (int i = 0; i < len; i++)
            if (digit[i] != a.digit[i]) return false;
        return true;
    }
    bool operator != (very_long a)
    {
        if (len != a.len) return true;
        for (int i = 0; i < len; i++)
            if (digit[i] != a.digit[i]) return true;
        return false;
    }
    bool operator < (very_long a)
    {
        if (len < a.len) return true;
        if (len > a.len) return false;
        for (int i = len - 1; i >= 0; i--)
        {
            if (digit[i] < a.digit[i]) return true;
            if (digit[i] > a.digit[i]) return false;
        }
        return false;
    }
    bool operator <= (very_long a)
    {
        if (len < a.len) return true;
        if (len > a.len) return false;
        for (int i = len - 1; i >= 0; i--)
        {
            if (digit[i] < a.digit[i]) return true;
            if (digit[i] > a.digit[i]) return false;
        }
        return true;
    }
    bool operator > (very_long a)
    {
        very_long b;
        b = cpy();
        return a < b;
    }
    bool operator >= (very_long a)
    {
        very_long b;
        b = cpy();
        return a <= b;
    }
    bool operator == (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return b == c;
    }
    bool operator < (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return b < c;
    }
    bool operator <= (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return b <= c;
    }
    bool operator > (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return b > c;
    }
    bool operator >= (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return b >= c;
    }
    very_long operator + (very_long a)
    {
        int p = 0, l = max(len, a.len);
        very_long b;
        for (int i = 0; i < l; i++)
        {
            int x = digit[i] + a.digit[i] + p;
            if (len <= i) x -= digit[i];
            if (a.len <= i) x -= a.digit[i];
            b.digit[i] = x % 10;
            p = x / 10;
        }
        b.len = l;
        if (p != 0)
        {
            b.len++;
            b.digit[l] = p;
        }
        return b;
    }
    very_long operator - (very_long b)
    {
        very_long a, c;
        a.len = len;
        for (int i = 0; i < len; i++)
            a.digit[i] = digit[i];
        if (a < b) swap(a, b);
        int p = 0;
        for (int i = 0; i < a.len; i++)
        {
            int x = a.digit[i] - b.digit[i] - p;
            if (b.len <= i) x += b.digit[i];
            p = 0;
            if (x < 0)
            {
                p = 1;
                x += 10;
            }
            c.digit[i] = x;
        }
        c.len = a.len;
        while (c.digit[c.len - 1] == 0 && c.len > 1)
            c.len--;
        return c;
    }
    very_long operator * (very_long a)
    {
        very_long b, c;
        c = 0;
        if (a == 0) {
            return c;
        }
        for (int i = 0; i < len; i++)
        {
            if (digit[i] != 0)
            {
                int p = 0;
                for (int j = 0; j < i; j++)
                    b.digit[j] = 0;
                for (int j = 0; j < a.len; j++)
                {
                    int x = digit[i] * a.digit[j] + p;
                    b.digit[i + j] = x % 10;
                    p = x / 10;
                }
                b.len = i + a.len;
                if (p != 0)
                {
                    b.len++;
                    b.digit[i + a.len] = p;
                }
                c = c + b;
            }
        }
        return c;
    }
    very_long operator + (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return b + c;
    }
    very_long operator - (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return b - c;
    }
    very_long operator * (int a)
    {
        very_long b, c;
        c = a;
        b = cpy();
        return c * b;
    }
    very_long operator / (int a)
    {
        very_long b;
        long long x = 0;
        b.len = len;
        for (int i = len - 1; i >= 0; i--)
        {
            x = x * 10 + digit[i];
            b.digit[i] = x / a;
            x %= a;
        }
        while (b.len > 1 && b.digit[b.len - 1] == 0)
            b.len--;
        return b;
    }
    int operator % (int a)
    {
        int result = 0;
        for (int i = len - 1; i >= 0; i--)
            result = (result * 10 + digit[i]) % a;
        return result;
    }
};

void print(very_long a) {
    for (int i = a.len - 1; i >= 0; --i) {
        printf("%d", a.digit[i]);
    }
}

very_long str_to_very_long(char s[max_l])
{
    very_long a;
    a.len = strlen(s);
    for (int i = 0; i < a.len; i++)
        a.digit[a.len - i - 1] = s[i] - '0';
    return a;
}

very_long step(very_long a, int b)
{
    if (b == 0)
    {
        very_long x;
        x = 1;
        return x;
    }
    if (b == 1) return a;
    if (b % 2 == 0) return step(a * a, b / 2);
    return a * step(a, b - 1);
}

bool cmp(very_long a, very_long b)
{
    return a < b;
}

const int max_n = 5555, inf = 111111111;

int n, x[max_n];
very_long max1, ans[max_n], two, sum;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> x[i];
    }
    ans[0] = 0;
    max1 = 0;
    two = 2;
    for (int i = 1; i < n; ++i) {
        if (s[i] == "win") {
            ans[i] = max1;
        } else {
            int last = -1;
            for (int j = 0; j < i; ++j) {
                if (s[j] == "win" && x[j] == x[i]) {
                    last = j;
                }
            }
            if (last == -1) {
                ans[i] = ans[i - 1];
            } else {
                sum = ans[last - 1] + step(two, x[i]);
                if (ans[i - 1] < sum) {
                    ans[i] = sum;
                    max1 = sum;
                } else {
                    ans[i] = ans[i - 1];
                }
            }
        }
    }
    print(ans[n - 1]);
    return 0;
}