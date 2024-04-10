#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll LST = 1;

ll divide_gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = divide_gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll xx(ll a, ll b, ll c) {
    ll d, x, y;
    d = divide_gcd(a, b, x, y);
    a = a / d;
    b = b / d;
    c = c / d;
    d = divide_gcd(a, b, x, y);
    x = x * c;
    y = y * c;
    ll new_x, new_y;
    new_x = (x % b + b) % b;
    new_y = (c - new_x * a) / b;
    return new_x;
}

//! Returns b/a (mod m)
ll divide(ll a, ll b, ll m) {
    ll x = xx(a, -m, b);
    x = (x%m);
    if (x < 0)
        x += m;
    return x;
}

const int mx = 300000;
int n, m, sz[mx], dp[mx], p[mx];
bool used[mx];
vector<int> num[mx], way;

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

int count_dp(int x) {
    if (dp[x] != -1)
        return dp[x];
    if (x == 1) {
        dp[x] = sz[x];
        return dp[x];
    }
    dp[x] = 0;
    for (int i = 1; i*i <= x; ++i) {
        if (x % i == 0) {
            if (i != x) {
                if (sz[x] + count_dp(i) > dp[x]) {
                    dp[x] = sz[x] + count_dp(i);
                    p[x] = i;
                }
            }
            if ((x/i) != x) {
                if (sz[x] + count_dp(x/i) > dp[x]) {
                    dp[x] = sz[x] + count_dp(x/i);
                    p[x] = x/i;
                }
            }
        }
    }
    return dp[x];
}

void print(int x, int lst) {
    for (int i = 0; i < sz[x]; ++i) {
        if (i == 0) {
            cout << divide(lst, num[x][i], m) << " ";
        }
        else {
            cout << divide(num[x][i-1], num[x][i], m) << " ";
        }
        LST = num[x][i];
    }
}

int main()
{
    for (int i = 0; i < mx; ++i) {
        used[i] = 0;
        sz[i] = 0;
        dp[i] = -1;
        p[i] = -1;
    }
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        used[temp] = 1;
    }
    for (int i = 0; i < m; ++i) {
        if (used[i] == 0) {
            int g = gcd(i, m);
            num[g].push_back(i);
            sz[g]++;
        }
    }
    count_dp(m);
    int pointer = m;
    way.push_back(m);
    while (pointer != 1) {
        pointer = p[pointer];
        way.push_back(pointer);
    }
    cout << dp[m] << endl;
    LST = 1;
    for (int i = way.size()-1; i >= 0; --i) {
        print(way[i], LST);
    }
    return 0;
}