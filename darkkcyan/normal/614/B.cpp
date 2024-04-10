#include <bits/stdc++.h>

using namespace std;

#define ffff(i, a, b, c) for (i a; i b; i c)
#define fff(i, a, b) ffff (i, = a, != b, ++)
#define ff(i, n) fff(i, 0, n)
#define all(v) v.begin(), v.end()

int main (void) {
    ios_base::sync_with_stdio(0);
    int i, j, l;

    int n;
    string input;
    cin >> n >> ws;
    getline(cin, input);

    input += ' ';
    long long int nonBeautifulNumIndex = -1;
    bool haveZero = false;
    long long int tailZeroCount = 0;

    i = 0;
    while (n > 0) {
        while (input[i] == ' ') ++i;
        --n;
        if (input[i] == '0') {
            haveZero = true;
            // cerr << "have zero\n";
            break;
        }
        if (input[i] != '1') {
            // cerr << "nonBeautifulNumIndex = " << i << '\n';
            nonBeautifulNumIndex = i;
            while (input[i] != ' ') ++i;
            continue;
        }

        j = i;
        ++i;
        // cerr << j;
        while (input[i] != ' ') {
            if (input[i] != '0') {
                nonBeautifulNumIndex = j;
            }
            ++i;
        }
        if (nonBeautifulNumIndex != j) {
            tailZeroCount += i - j - 1;
        }
        // cerr << ' ' << i << '\n';
    }

    if (haveZero) {
        cout << 0;
        return 0;
    }

    i = nonBeautifulNumIndex;
    while (i != -1 and input[i] != ' ') {
        cout << input[i];
        ++i;
    }

    if (i == -1) cout << "1";

    ff (i, tailZeroCount) cout << 0;

    cout << '\n';
    return 0;
}