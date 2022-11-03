#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> buffer;

void Shift(string& s, int l, int r, int k)
{
    int len = r - l + 1;
    k %= len;
    
    buffer.assign(s.begin() + l, s.begin() + r + 1);
    for (int i = l; i <= r; ++i) {
        int j = i - k;
        if (j < l) {
            j += len;
        }
        s[i] = buffer[j - l];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    buffer.reserve(s.length());

    int m;
    cin >> m;
    for (int q = 0; q < m; ++q) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        Shift(s, l, r, k);
    }
    cout << s << endl;

    return 0;
}