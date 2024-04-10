#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
using ll = long long;

constexpr int N = 100005;

vector<int> adj [N];
int val [N];
int xor_sum [2];
int cnt [2];
map<int, int> has [2];


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
    } else
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


int dfs(int v, int p, int even) 
{

	xor_sum[even] ^= val[v];
	cnt[even]++;
	has[even][val[v]]++;

	int res = even;

	for (int u : adj[v])
        {
		if (u != p) 
                {
			res = dfs(u, v, even ^ 1);
		}
	}

	return res;
}

int main(void) {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) 
        {
		cin >> val[i];
	}

	for (int i = 2; i <= n; i++) 
       {
		int u;
		cin >> u;
		adj[i].push_back(u);
		adj[u].push_back(i);
	}

	int res = dfs(1, -1, 0);
	ll ans = 0;

	if (xor_sum[res] == 0) {
		ans += cnt[res] * 1LL * (cnt[res]-1)/2;
		ans += cnt[res^1] * 1LL * (cnt[res^1]-1)/2;
	}

	for (int i = 0; i < 1<<24+1; i++) {
		if (has[res].find(i) != has[res].end()) 
               {
			int needed = xor_sum[res] ^ i;
			if (has[res^1].find(needed) != has[res^1].end()) 
                       {
				ans += has[res][i] * 1LL * has[res ^ 1][needed];
			}
		}
	}

      cout << ans << "\n";

	return 0;
}