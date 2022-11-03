#include <iostream>
#include <vector>
using namespace std;

const vector<int> COST = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> count(10, 0);

    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        int x = i;
        while (x) {
            ++count[x % 10];
            x /= 10;
        }
    }

    long long result = 0;
    for (int i = 0; i < 10; ++i) {
        result += 1LL * count[i] * COST[i];
    }
    cout << result << endl;

    return 0;
}