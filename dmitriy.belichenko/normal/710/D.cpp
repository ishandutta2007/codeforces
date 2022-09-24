

#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define mp make_pair
#define ll long long
using namespace std;
const int P = 2000;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a1, b1, a2, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
    ll g = gcd(a1, a2);
    if (a1 < a2) {
        swap(a1, a2);
        swap(b1, b2);
    }
    ll mb = max(b1, b2);
    l = max(mb , l);
    if (l > r) {
        cout << 0 << "\n";
        return 0;
    }
    //cout << b1 % g << " " << b2 % g << "\n";
    if ((g + b1 % g) % g != (g + b2 % g) % g) {
        cout << 0 << "\n";
        return 0;
    }
    bool flag = 0;
    
    if (a1 < P) {
        b1 = (b1 < l) ? (b1 + (l - b1 + a1 - 1) / a1 * a1) : b1;
        while (b1 < r + 1 && (b2 - b1) % a2) {
            b1 += a1;
        }
        if (b1 < r + 1) {
            cout << (r - b1) / (a1 * a2 / gcd(a1, a2)) + 1 << "\n";
            flag = 1;
        }
    } else {
        while (b1 < l) b1 += a1;
        ll cnt = 0;
     //   cout << b1 << "\n";

        while (b1 < r + 1) {
            b1 += a1;
            cnt += ((b1 - a1 - b2) % a2 == 0);
        }
        cout << cnt << "\n";
        flag = 1;
    }
    
    if (!flag) {
        cout << 0 << "\n";
    }
    
}