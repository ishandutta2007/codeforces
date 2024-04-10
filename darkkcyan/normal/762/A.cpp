#include<bits/stdc++.h>
using namespace std;

void answer( long long num) {
    cout << num;
    exit(0);
}
int main() {
    long long n, k; cin >> n >> k;
    long long i;
    vector<long long> divs;
    for (i = 1; i * i <= n; ++i) {
        if (n % i) continue;
        --k;
        if (i * i != n) divs.push_back(n / i);
        if (k == 0) answer(i);
    }
    --k;
    if (k >= divs.size()) answer(-1);
    else answer(divs.rbegin()[k]);
}