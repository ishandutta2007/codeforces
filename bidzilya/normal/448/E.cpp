#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

const int max_mem = 1e5;

ll n, k;

int ans[max_mem];
int m;

vector<ll> d;

vector<vector<int> > D;

void show()
{
    for (int i = 0; i < m; ++i)
        cout << d[ans[i]] << " ";
    cout << endl;
    exit(0);
}

void add_to_ans(int x)
{
    ans[m] = x;
    ++m;
    if (m == max_mem) show();
}

void dfs(int a, int b)
{
    if (b == 0) {
        add_to_ans(a);
    } else {
        if (D[a].size() == 1) {
            add_to_ans(0);
        } else if (D[a].size() == 2) {
            for (int i = 0; i < b; ++i) {
                add_to_ans(0);
            }
            add_to_ans(a);
        } else {
            for (int i = 0; i < (int) D[a].size(); ++i)
                dfs(D[a][i], b - 1);
        }
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n >> k;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    if (k == 0) {
        cout << n << endl;
        return 0;
    }
    
    if (k >= max_mem) {
        for (int i = 0; i < max_mem; ++i)
            cout << 1 << " ";
        cout << endl;
        return 0;
    }

    for (ll i = 1; i * i <= n; ++i) 
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n) {
                d.push_back(n / i);
            }
        }

    sort(d.begin(), d.end());
    
    D.resize(d.size());
    
    for (int i = 0; i < (int) d.size(); ++i) {
        for (int j = 0; j <= i; ++j) 
            if (d[i] % d[j] == 0)
                D[i].push_back(j);
    }

    m = 0;
    
    dfs(d.size() - 1, k);

    show();
}