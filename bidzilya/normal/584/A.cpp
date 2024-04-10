#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Check(const vector<int>& digits, const int t) {
    int sum = 0;
    for (int i = (int) digits.size() - 1; i >= 0; --i) {
        const int x = digits[i];
        sum *= 10;
        sum += x;
        sum %= t;
    }
    return sum == 0;
}

int main() {
    int n, t;
    cin >> n >> t;
    
    if (n == 1) {
        if (t == 10) {
            cout << -1 << endl;
        } else {
            cout << t << endl;
        }
        return 0;
    }
    
    vector<int> digits(n, 0);
    digits.back() = 1;
    for (int last = 0; last < 100; ++last) {
        if (n == 2 && (last / 10) == 0) {
            continue;
        }
        digits[0] = last % 10;
        digits[1] = last / 10;
        if (Check(digits, t)) {
            reverse(digits.begin(), digits.end());
            for (int x : digits) {
                cout << x;
            }
            cout << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}