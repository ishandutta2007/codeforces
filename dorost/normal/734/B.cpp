#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max (min ({a, c, d}) * 8 + min (a - min({a, c, d}), b), min (a, b) + min ({c, d, a - min (a, b)})) * 32;
}