#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int n, a[1003];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int s = 0, res = 0;
    while (true) {
        for (int i=0;i<n;i++)
            if (a[i] <= s)
				a[i] = n + 1, s++;
        if (s == n)
			break;
        res++;
        for (int i=n-1; i>=0; i--)
            if (a[i] <= s)
				a[i] = n+1, s++;
        if (s == n)
			break;
        res++;
    }
    cout << res << endl;
}