#include <iostream>

using namespace std;

int main() {
    int n,m,sum;
    cin >> n >> m;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a,b;
            cin >> a >> b;
            if (a == 1 || b == 1) {
                sum++;
            }
        }
    }
    cout << sum << endl;
}