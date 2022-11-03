#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a;
    cin >> n >> a;

    int result;
    if (a & 1) {
        result = (a >> 1) + 1;
    } else {
        result = ((n - a) >> 1) + 1;
    }
    cout << result << endl;

    return 0;
}