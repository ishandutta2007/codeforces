#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int max_n = 33;
const int max_c = 26;

int n;
string s[max_n];
bool in1[max_c];
bool in2[max_c][max_c];

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    for (int i = 0; i < n; ++i)
        for (int pos = 0; pos < (int) s[i].length(); ++pos) {
            int c1 = s[i][pos] - 'a';
            in1[c1] = true;
            if (pos + 1 < (int) s[i].length()) {
                int c2 = s[i][pos + 1] - 'a';
                in2[c1][c2] = true;
            }
        }

    for (int c1 = 0; c1 < max_c; ++c1)
        if (!in1[c1]) {
            cout << (char)(c1 + 'a') << endl;
            return 0;
        }
    
    for (int c1 = 0; c1 < max_c; ++c1)
        for (int c2 = 0; c2 < max_c; ++c2)
            if (!in2[c1][c2]) {
                cout << (char)(c1 + 'a') << (char)(c2 + 'a') << endl;
                return 0;
            }

    return 0;
}