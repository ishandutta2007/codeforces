#include<algorithm>
#include<iostream>
using namespace std;
int ans[305][10005];
int n, m, k ,s;
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
int main()
{
    int n;
    
    cin >> n;
    long long ans;
    ans = (n -1)/2;
    cout << ans;
}