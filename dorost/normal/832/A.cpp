#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    cout << (n / k % 2 ? "YES" : "NO");
}