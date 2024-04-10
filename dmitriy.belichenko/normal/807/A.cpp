#include<algorithm>
#include<iostream>
#include<vector>
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

/*
 4
 3 10 1 2
 7 14 3 8
 20 70 2 7
 5 6 1 14
 */
int main()
{
    int n;
    cin >>  n;
    vector<int> a(n);
    vector<int> b(n);
    bool r  = 0, m = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if(a[i] != b[i])
        {
            r = 1;
            break;
        }
    }
    if(r == 1)
    {
        cout <<"rated" << "\n";
    }
    else
    {
        for(int i =0 ; i < n - 1; i++)
            if(a[i+1] > a[i]) m = 0;
        if(m)cout << "maybe" << "\n";
        else cout << "unrated" << "\n";
    }
}