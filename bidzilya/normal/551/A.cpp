#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (a[j] > a[i]) {
                ++b[i];
            }
        }
        cout << b[i] << " ";
    }
    cout << endl;





    return 0;
}