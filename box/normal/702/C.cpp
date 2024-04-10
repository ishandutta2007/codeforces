#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> city, cell;

bool OK(long long k) {
    // is each city at most k distant from a cellular tower?
    for(int i:city) {
        auto first = lower_bound(cell.begin(), cell.end(), i-k);
        auto last = upper_bound(cell.begin(), cell.end(), i+k);
        if(!(first != cell.end() && first < last)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long a, b; cin >> a >> b;
    while(a--) {
        long long i; cin >> i;
        city.push_back(i);
    }
    while(b--) {
        long long i; cin >> i;
        cell.push_back(i);
    }
    long long low = 0, high = 20000000001, ans = -1;
    while(low <= high) {
        long long mid = (low + high) >> 1;
        if(OK(mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    cout << ans << endl;
}