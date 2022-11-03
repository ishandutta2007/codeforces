#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int kAlphabetSize = 26;

vector<int> GetRepr(const string& s)
{
    vector<int> r(kAlphabetSize, 0);
    for (int i = 0; i < (int) s.length(); ++i) {
        char c = s[i];
        ++r[c - 'a'];
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    vector<int> ra = GetRepr(a);
    vector<int> rb = GetRepr(b);
    vector<int> rc = GetRepr(c);

    int ansb = 0;
    int ansc = 0;

    int max_b = a.length();
    for (int i = 0; i < kAlphabetSize; ++i) {
        if (rb[i] > 0) {
            max_b = min(max_b, ra[i] / rb[i]);
        }
    }

    for (int cb = 0; cb <= max_b; ++cb) {
        int cc = a.length();
        for (int i = 0; i < kAlphabetSize; ++i) {
            if (rc[i] > 0) {
                cc = min(cc, (ra[i] - cb * rb[i]) / rc[i]);
            }
        }
        if (cb + cc > ansb + ansc) {
            ansb = cb;
            ansc = cc;
        }
    }

    for (int i = 0; i < ansb; ++i) {
        cout << b;
    }
    for (int i = 0; i < ansc; ++i) {
        cout << c;
    }
    for (int i = 0; i < kAlphabetSize; ++i) {
        ra[i] -= (rb[i] * ansb + rc[i] * ansc);
    }
    for (int i = 0; i < kAlphabetSize; ++i) {
        for (int j = 0; j < ra[i]; ++j) {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;

    return 0;
}