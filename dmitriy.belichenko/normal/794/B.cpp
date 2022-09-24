#include<algorithm>
#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;
long long ans[305][10005];
long long m, k ,s;
static long parsenum (long j, long l)
{
    string k = "";
    long cur = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        cur *= 10;
        cur += k[i] - '0';
    }
    return cur;
}

static long long gcd(long a, long b)
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

static bool pri(long long k)
{
    if (k == 1) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return 1;
}
void print ()
{
    for(long long i = 0; i <= k ;i++)
    {
        for(long long j = 0; j <=s; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}
const int N = 200005;

bool usd[N];
long long p[N];
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
int solve()
{
     long long n,m , d;
    return 0;
    cin >> n >> m >> d;

    vector<pair< long long , pair<long long, long long> > > c(n);
       for(long long i = 0; i < n; i++)
    {
        c[i].second.first = 1000000;
        c[i].second.second = 1000000;
        long long u , v;
        cin >> u >> v;
        char ch;
        cin >> ch;
        c[i].first = u;
        if(ch == 'C') c[i].second.first = v;
        else c[i].second.second = v;
    }
    sort(c.rbegin(), c.rend());
    long long ans1 = 0 , ind1 = 0;
    int q = m;
    int p = d;
    for(int i = 0; i < n; i++)
    {
        if(ind1 == 2) break;

        if(c[i].second.first <= q ) ans1+= c[i].first , ind1 ++;
        if(ind1 == 2) break;
        else
         if(c[i].second.second <= d ) ans1+= c[i].first , ind1 ++;
        if(ind1 == 2) break;

    }
   // cout << ans1 << "\n" << ind1 << "\n";
    if(ind1 != 2) ans1 = 0;
    ind1 = 0; long long ans2 = 0;
   int l =-1;
   int r= n-1;
  long long mx2=0;
   long long mx1=-1;
     sort(c.begin(), c.end());
    while (l<r)
    {
        while (l<r-1 && c[l + 1].second.second<=d- c[r].second.second) {
            l++;
            if (c[l].first >mx2)
            {
                mx2 = c[l].first;
                mx1 = l;
            }
        }
        if (c[mx1].second.second +c[r ].second.second <= d) ans2=max(ans2, c[mx1].first+c[r].first);
        r--;
    }
    if(mx1 == r ) ans2 = 0;
    
    
    long long ans3 = 0;
    l =-1;
    r= n-1;
     mx2=0;
     mx1=-1;
    sort(c.begin(), c.end());
    while (l<r)
    {
        while (l<r-1 && c[l + 1].second.first<= m- c[r].second.first) {
            l++;
            if (c[l].first >mx2)
            {
                mx2 = c[l].first;
                mx1 = l;
            }
        }
        if (c[mx1].second.first +c[r ].second.first <= m ) ans3=max(ans3, c[mx1].first+c[r].first);
        r--;
    }
    if(mx1 == r ) ans3 = 0;
    cout << max(ans1 , max(ans2 , ans3)) << "\n";
    return 0;
}


vector<pair<long long, int> > color[3];

int ptr[3];


long long a, b;
long long h, w;

vector<long long> g(N);

long long dp[40][N];

bool ins(long long a, long long b, long long c, long long d)
{
    if ((a <= c && b <= d) || (a <= d && b <= c))
        return true;
    return false;
}


using namespace std;
int x[100005];
int main()
{
    int n;
    long double h;
    cin >> n >> h;
    for (int i = 1; i < n; i++) {
        long double lg = 0,rg = 1.0;
        long double need = ((long double)i) / (long double)(n);
        cout << setprecision(6) << fixed << sqrt(need) * (long double)h << " ";
    }

}