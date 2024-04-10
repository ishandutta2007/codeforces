#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

static long parseans(long j, long l)
{
    string k = "";
    long ps = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        ps *= 10;
        ps += k[i] - '0';
    }
    return ps;
}


static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    } else
    {
        return gcd(b, a % b);
    }
}

static bool pri(long long k)
{
    if (k == 1) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
int n;
int main()
{
   /* int m , b;
    cin >> m >> b;
    int x = m * b;
    int y = b;
    */
    
   
    cin>>n;
    int a[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool ok=0;
            if (a[i][j] == 1) ok = 1;
            for (int k=0; k <n && !ok; k++)
            {
                for (int p = 0; p < n && !ok; p++)
                {
                    if (k != i && p != j && a[i][p] == a[i][j] - a[k][j]) ok=1;
                }
            }
            if (!ok)
            {
                cout<<"No";
                return 0;            }
            }
    }
    cout<<"Yes";
    return 0;

}