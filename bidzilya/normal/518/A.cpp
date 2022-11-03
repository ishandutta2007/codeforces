#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    int n = s.length();
    vector<int> res(n);
    const int kAlphabetSize = 26;
    for (int i = 0; i < n; ++i) {
        res[i] = s[i] - 'a';
    }

    int tmp = 0;
    ++res[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        res[i] += tmp;
        tmp = res[i] / kAlphabetSize;
        res[i] %= kAlphabetSize;
    }

    const string kFailed = "No such string";
    if (tmp > 0) {
        cout << kFailed << endl;
        return 0;
    }

    string ans;
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = (char)('a' + res[i]);
    }

    if (ans > s && ans < t) {
        cout << ans << endl;
    } else {
        cout << kFailed << endl;
    }

    return 0;
}