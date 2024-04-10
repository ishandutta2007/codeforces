#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
typedef long long ll;

int arr[55];

int n, k, a = 0;

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for (int i = 0; i < n; ++i) {
        cout << "1 " << arr[i] << "\n";
        ++a;
        if (a == k)
            return 0;
    }
    string all = "";
    for (int i = 0; i < n; ++i) {
        stringstream ss;
        ss << all << arr[i] << " ";
        all = ss.str();
        for (int j = i + 1; j < n; ++j) {
            cout << i + 2 << " " << all << arr[j] << "\n";
            ++a;
            if (a == k)
                return 0;
        }
    }
}