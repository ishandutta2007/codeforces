#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int ct = 0; ct < t; ++ct) {
        int n;
        cin >> n;
        long long sum = 1LL * n * (n + 1) / 2;
        for (int i = 1; i <= n; i <<= 1) {
            sum -= 2LL * i;
        }
        cout << sum << endl;
    }

    return 0;
}