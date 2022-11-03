#include <iostream>
#include <algorithm>
#include <vector>
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
        a[i] += i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        a[i] -= i;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            cout << ":(" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;




    return 0;
}