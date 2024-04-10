#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct event {
    long long time;
    bool dasha;
    const bool operator<(const event o) const {
        return time < o.time;
    }
};

int main() {
    long long a, b; cin >> a >> b;
    long long ll = a*b/__gcd(a,b);
    vector<event> v;
    for(int i=1; i<ll/a; i++) v.push_back({i*a, true});
    for(int i=1; i<ll/b; i++) v.push_back({i*b, false});
    v.push_back({ll, a>b});
    sort(v.begin(), v.end());
    long long d = 0, prev = 0;
    for(const event e:v) {
        if(e.dasha) d += e.time - prev;
        prev = e.time;
    }
    if(d > ll-d) cout << "Dasha" << endl;
    else if(d < ll-d) cout << "Masha" << endl;
    else cout << "Equal" << endl;
}