#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define count count123123

const int MAX_LEN = 18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    map<long long, int> count;

    for (int test = 0; test < tests; ++test) {
        char tp;
        string s;
        cin >> tp >> s;

        reverse(s.begin(), s.end());
        while (s.length() < MAX_LEN) {
            s.push_back('0');
        }
        reverse(s.begin(), s.end());

        for (int i = 0; i < (int) s.length(); ++i) {
            int x = s[i] - '0';
            if (x & 1) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }

        long long num = 0;
        for (int i = 0; i < (int) s.length(); ++i) {
            num = num * 10 + (s[i] - '0');
        }

        if (tp == '-') {
            --count[num];
        } else if (tp == '+') {
            ++count[num];
        } else {
            auto itr = count.find(num);

            int result = (itr == count.end() ? 0 : itr->second);

            cout << result << '\n';
        }
    }
    cout.flush();

    return 0;
}