#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
long long inf = 1 << 62;
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

int cur = 1;

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

static bool pri(long long k)
{
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}

double binpow (double a, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return binpow (a, n-1) * a;
    else {
        int b = binpow (a, n/2);
        return b * b;
    }
}
vector<int> calcz (string s)
{
    int n = s.length();
    vector<int> z (n);
    int l = 0, r = 0;
    for (int i = 1 ; i<n; i++)
    {
        if (i <= r)
        {
            z[i] = min (r - i+ 1, z[i - l]);
        }
        while (i + z[i] < n && s[ z[i] ] == s[i + z[i] ]) z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}


vector<int> calcpref(string s)
{
    vector<int> p(s.size() + 1);
    int n = s.length();
    p[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[p[i]] !=s[i-1]) p[i] = p[p[i]];
        if (s[p[i]] == s[i-1]) p[i]++;
    }
    return p;
}


int main()
{
    int k , n;
    cin >> k >> n;
    vector<int>a(k) , b(n);
    for(int i = 0; i < k; i++)
        cin >> a[i];
    for(int i = 0; i <  n; i++)
        cin >> b[i];
    vector<int> ps(k);
    ps[0] = a[0];
    for(int i = 1 ; i < k; i++)
    {
        ps[i] = ps[i - 1] + a[i];
    }
    set<int> start;
    for(int i = 0; i < k; i++)
    {
        start.insert(b[0] - ps[i]);
    }
    set<int> has;
    int cnt = 0;
  
    for(auto st : start)
    {
        bool flag = 1;
        for(int i = 0; i < k; i++)
        {
            has.insert(st + ps[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(has.count(b[i]) == 0)
                flag = 0;
        }
        if(flag)
            cnt++;
        has.clear();
    }
    cout << cnt << "\n";
    return 0;
    
}