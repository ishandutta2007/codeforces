#include <bits/stdc++.h>

using namespace std;
const int N = 4;
string s[N];

int main() {
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = 0;
            if (s[i][j] == '#')
                x++;
            if (s[i + 1][j] == '#')
                x++;
            if (s[i + 1][j + 1] == '#')
                x++;
            if (s[i][j + 1] == '#')
                x++;
            if (x == 1 || x == 3 || x == 4 || x == 0)  {
                return cout << "YES", 0;
            }
        }
    }
    cout << "NO";
}