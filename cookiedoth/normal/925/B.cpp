#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <functional>
#define ll long long
#define null NULL
#define all(a) a.begin(), a.end()

using namespace std;

const ll MOD = 1e9 + 7;

const ll mx = 5e5;
ll n, pos1, pos2;
ll x1, x2;
vector<pair<ll, ll> > a;

bool check() {
    pos1 = -1;
    pos2 = -1;
    for (ll i = 0; i < n; ++i) {
        if (a[i].first * (i + 1) >= x1) {
            pos1 = i;
            break;
        }
    }
    if (pos1 == -1) {
        return 0;
    }
    for (ll i = pos1 + 1; i < n; ++i) {
        if (a[i].first * (i - pos1) >= x2) {
            pos2 = i;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> x1 >> x2;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    if (check()) {
        cout << "Yes" << endl;
        cout << pos1 + 1 << " " << pos2 - pos1 << endl;
        for (ll i = 0; i <= pos1; ++i) {
            cout << a[i].second + 1 << " ";
        }
        cout << endl;
        for (ll i = pos1 + 1; i <= pos2; ++i) {
            cout << a[i].second + 1 << " ";
        }
        cout << endl;
        return 0;
    }
    swap(x1, x2);
    if (check()) {
        cout << "Yes" << endl;
        cout << pos2 - pos1 << " " << pos1 + 1 << endl;
        for (ll i = pos1 + 1; i <= pos2; ++i) {
            cout << a[i].second + 1 << " ";
        }
        cout << endl;
        for (ll i = 0; i <= pos1; ++i) {
            cout << a[i].second + 1 << " ";
        }
        cout << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}