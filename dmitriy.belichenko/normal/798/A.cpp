#include<algorithm>
#include<iostream>
using namespace std;
int ans[305][10005];
long long m, k ,s;
static long parsenum(long j, long l)
{
    string k = "";
    long cur = 0;
    for (int i = (int) j; i <= l; ++i)
    {
        cur *= 10;
        cur += k[i] - '0';
    }
    return cur;
}

static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

static bool pri(int k)
{
    if (k == 1) return false;
    for (int i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
void print()
{
    for(int i = 0; i <= k ;i++)
    {
        for(int j = 0; j <=s; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}
long long binpow (long long a, long long n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow (a, n-1) * a) % (1000000007);
    else {
        long long b = binpow (a, n/2) % (1000000007);
        return ((b % (1000000007) )* (b % (1000000007))) % (1000000007);
    }
}
int main()
{
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        for(int c = 0; c < 26; c++)
        {
            char x = c + 'a';
            if (s[i] == x) continue;
            string t = s;
            t[i] = x;
            string u(t.rbegin(), t.rend());
            if (t == u) {
                puts("YES");
                return 0;
            }
        }
    }
    
    puts("NO");
    return 0;
}