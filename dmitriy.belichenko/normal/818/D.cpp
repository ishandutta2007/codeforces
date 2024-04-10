#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
long long inf = 1LL << 62;
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
int cnt = 0;
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
map<int, int> m;
map<int, set<int> > m1;
static bool pri(long long k)
{
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
vector<bool> used(10000);
vector<int> g[10005];
vector<int> ans;
int n , k;
void dfs(int u)
{
    used[u] = 1;
    for( auto v : g[u])
    {
       if(!used[v]) dfs(v);
    }
    ans.push_back(u);
}
void topsort()
{
    for(int i = 0; i < n; i++) used[i] = 0;
    ans.clear();
    for(int i = 0; i < n; i++)
    {
        if(!used[i]) dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(20);
        int n, A;
        cin >> n >> A;
        set<int> fct;
        int cntA = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (fct.find(x) != fct.end())
                continue;
            if (x == A)
                cntA++;
            else
            {
                if (m.find(x) == m.end())
                {
                    if (cntA != 0)
                    {
                        fct.insert(x);
                    }
                    else
                    {
                        m[x] = 1;
                        m1[1].insert(x);
                    }
                }
                else
                {
                    m1[m[x]].erase(x);
                    if ((m1[m[x]]).size() == 0)
                    {
                        m1.erase(m[x]);
                    }
                    m[x]++;
                    m1[m[x]].insert(x);
                }
            }
            while ( m1.size() != 0 && m1.begin()->first< cntA)
            {
                for (int y : m1.begin()->second)
                {
                    m.erase(y);
                    fct.insert(y);
                }
                m1.erase(m1.begin());
            }
        }
        cout << (m1.size() ? *(m1.begin()->second.begin()) : -1) << "\n";
        return 0;
    
}