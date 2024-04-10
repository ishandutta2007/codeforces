/*
#include<algorithm>
#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<set>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <cstdio>
#include <functional>
#include <random>
#include <ctime>
#include <cassert>
#include <bitset>
#include <unordered_map>
#include <math.h>

using namespace std;
#define N 200005
#define M 20
#define F 450
mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornv(i, n) for (int i = n - 1; i >= 0; i--)
#define pii pair<int, int>
#define forlr(i, l, r) for (int i = l; i <= r; i++)
#define forlrv(i, l, r) for (int i = r; i >= l; i--)
#define read(x) scanf("%d", &x)
#define print(x) printf("%d ", x)
#define printl(x) printf("%d\n", x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
const long double eps = 1e-9;
const int inf = 1e9;
const int mod = 1e9 + 7;
const ll infinity = 2 * 1e18;
#define p p2
#define endl '\n'



//long long a[N];

using namespace std;

bool solve2(int n , vector<long long> &a)
{
   long long sum = 0;
    for (int i = 0; i < n; ++i) {
      
        sum += a[i];
    }
    if (sum % 2 != 0) {
        return 0;
       
    }
    sum >>= 1;
    for (int iter = 0; iter < 2; ++iter) {
        set <long long> s;
        long long cur = 0;
        for (int i = 0; i < n; ++i)
        {
            s.insert(cur);
            if (cur == sum) {
               // puts("YES");
                return 1;
            }
            if (s.count(sum - a[i])) {
               // puts("YES");
                return 1;
            }
            cur += a[i];
        }
        reverse(a.begin(), a.end());
    }
    return 0;

}
using namespace std;

#define ll long long

ll each;
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

int solve1(int n)
{
  
    int res = 1;
    n++;
    int mult = 1;
    while (n >= 10) {
        if (n % 10 != 0) {
            res += mult * (10 - (n % 10));
        }
        n = (n + 9) / 10;
        mult *= 10;
    }
    return res;
}
int solve2(int n)
{
   
   
    int c = 0;
    int last = -1;
    int b = 0;
    int tmp = n;
    while (n) {
        c += n % 10 == 0;
        last = n % 10;
        b++;
        n /= 10;
    }
    int now = 1;
    for (int i = 0; i < b - 1; i++)
        now *= 10;
   return  now - (tmp % now);
    
}

int main()
{
    
    for(int i =0 ; i < 100000000; i++)
    {
        srand(time(NULL));
    int n;
       
    n = rand() % 100000000;
        
       //  cout << n << "\n";
    //vector<long long>a;
  //  a.resize(n);
       if(n != 0)
        {
  
    if(solve1(n) != solve2(n) )
    {
        cout << n << "\n";
       
        return 0;
    }
        else
        {
            cout << "TEST " << i +1 << " PASSED" << "\n";
        }
    }
    }
} */
#include<algorithm>
#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<set>
#include<vector>
using namespace std;

using namespace std;
string t;
bool r[2005];
bool l[2005];
set<int> p;
vector<int> g[300005];
vector<int> color(200005);
const int N = 2 * 1000 + 3;
long long n , m;
void input()
{
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
long long ans[305][10005];

static long parsenum (long j, long l)
{
    string k = "";
    long sm = 0;
    for (long long i = (long long) j; i <= l; i++)
    {
        sm *= 10;
        sm += k[i] - '0';
    }
    return sm;
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
    int k , s;
    for(long long i = 0; i <= k ;i++)
    {
        for(long long j = 0; j <=s; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int w[N];

long long mpow(long long x, int p)
{
    if (!p) return 1;
    return (mpow(x * x, p / 2) * (p & 1 ? x : 1));
}

int solve1(int n)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    //if (n == 1000000000)
    // assert(false), exit(0);
    
    long long res = 2e18;
    for(int i =0 ; i <= 9; i++)
    {
        long long ans = 0;
        for(int j = 0; j < 15; j++)
        {
            ans = i * 1LL * mpow(10, j);
            if (ans > n)
                res = min(res, ans - n);
        }
    }
    return  res;
}
long long s = 0;

bool check(vector<long long> &a , int n)
{
    long long sm = 0;
    set<long long> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(sm);
        sm += a[i];
        if (sm == s  || st.count(s - a[i]))
        {
            return 1;
        }
        
    }
    return 0;
}

int used[200005];
int main()
{
    vector<long long >a , b;
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[n - i - 1] = a[i];
        s += a[i];
    }
    if (s % 2 != 0)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        s = s / 2;
    }
    if(check(a , n) || check(b , n))
    {
        cout << "YES" << "\n";
    }
    else
        cout << "NO" << "\n";
    return 0;
    
}