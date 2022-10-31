#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll n, arr[100010];
int main() {
    ll sum = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sum = sum + arr[i];
    }
    sort(arr + 1, arr + n + 1);
    ll tmp = 0;
    for(ll i = 1; i <= n; ++i) {
        sum += (arr[i] * (i-1) - tmp)*2;
        tmp += arr[i];
    }
    ll g = gcd(sum, n);
    cout << sum/g << ' ' << n/g << endl;
    return 0;
}