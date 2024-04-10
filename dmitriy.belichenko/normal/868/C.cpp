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
#include<unordered_map>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 1e3;
const int INF = 1e9;
const int MOD = 1e9 + 7;
vector<int> pt;
int n , k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    unordered_map<bitset<4>, int> m;
    vector<bitset<4>> a;
    for(int i = 0; i < n; i++)
    {
        bitset<4> p;
        for(int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            p[j] = a;
        }
        m[p]++;
        if(m[p] == 1) a.pb(p);
    }
    //   16
    for(int i = 1; i < (1 << a.size()) ; i++)
    {
        bitset<16> p = i;
        vector<int> cnt;
        cnt.resize(min(k , 4) , 0 );
        bool flag = 1;
        for(int j = 0; j <= a.size(); j++)
        {
            if(p[j])
            {
                for(int u = 0; u < min(4 , k); u++)
                {
                    cnt[u] += (int)(a[j][u]);
                }
            }
        }
        for(int t = 0; t < min(4 , k); t++)
        {
            // cout << i << " " << cnt[t] << " " << p.count() << "\n";
            if(2 * cnt[t] > p.count())
            {
                flag = false;
            }
        }
        if(flag)
        {
            //  cout << i << " " << p.count() << "\n";
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}