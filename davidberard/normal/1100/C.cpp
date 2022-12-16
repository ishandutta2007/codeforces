#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld PI = 3.14159265358979323;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int nn, rr;
    cin >> nn >> rr;
    ld n=nn;
    ld r=rr;
    ld t2 = PI/n;
    ld m = -sin(t2)*r/(-1.0+sin(t2));
    cout << fixed << setprecision(10) << m << endl;
    
    return 0;
}