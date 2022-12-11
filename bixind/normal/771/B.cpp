#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        s[i] = "Aa";
        if (i >= 26)
            s[i][0] = 'B';
        s[i][1] = ('a' + (i % 26));
    }
    for (int i = 0; i < n - k + 1; ++i) {
        string s1;
        cin >> s1;
        if (s1 == "NO") {
            s[i + k - 1] = s[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i] << ' ';
    }
    cout << endl;
    return 0;
}