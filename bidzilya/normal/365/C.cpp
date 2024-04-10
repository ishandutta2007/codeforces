#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 1e4 + 100;

ll n;
ll sum[max_n * 10];
ll ans;
string s;
ll a[max_n];
ll A;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> A;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) 
        a[i] = s[i] - '0';
    for (int i = 0; i < n; ++i) {
        int csum = 0;
        for (int j = i; j < n; ++j) {
            csum += a[j];
            ++sum[csum];
        }
    }
    ans = 0;
    for (int i = 0; i < n; ++i) {
        int csum = 0;
        for (int j = i; j < n; ++j) {
            csum += a[j];
            if (csum == 0) {
                if (A == 0)
                    ans += n * (n + 1) / 2;
            } else if (A % csum == 0 && A / csum < max_n * 10LL) {
                ans += sum[A / csum];
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}