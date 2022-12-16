#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 200200;
int n, z;
vector<int> x;

int bs() {
    int lo = 0, hi = n/2;
    while(lo < hi) {
        int m = (lo+hi+1)/2;
        bool good = true;
        int d = n-m;
        for(int i=0; i<m; ++i) {
            if(x[i+d]-x[i] < z) {
                good = false;
                break;
            }
        }
        if(good) {
            lo = m;
        } else {
            hi = m-1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> z;
    x.resize(n);
    for(auto& y : x) cin >> y;
    sort(x.begin(), x.end());
    cout << bs() << endl;
    return 0;
}