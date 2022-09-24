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
  /*  int n,m , d;
    cin >> n >> m >> d;
    vector<int> a(n);
    vector<int> c;
    vector<int> p;
    p.resize(n , 10000000);
    c.resize(n , 10000000);
    for(int i = 0; i < n; i++)
    {
        int u , v;
        cin >> u >> v;
        char ch;
        cin >> ch;
        if(ch == 'C') c[u-1] = v;
        else p[u - 1] = v;
    } */

    
        int n , t , k , d;
        int u1=0;
         cin>>n >> t ;
         cin >> k >> d;
        int c=0;
        while (c<n)
        {
            c = c + k;
            u1= u1 + t ;
        }
        c=0;
        int p1=0;
        int p2=d;
    while (p1<d)
    {
        c = c + k;
        p1= p1 + t;

    }
        while (c<n)
        {
            c = c + k;
            p2 = p2 + t;
            if (c <= n - 1)
            {
                c = c + k;
                p1= p1 + t;

            }
        }
       int ans = max(p1 , p2);
    if (ans - u1 < 0)
    {
        cout<<"YES";
    }
        else cout<<"NO";
    }