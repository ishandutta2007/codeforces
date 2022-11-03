#include <cstdio>
#include <cstring>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 10;
const int max_s = 1e5 + 100;

string s;
string b[max_n];
int n;
/*
ifstream cin("input.txt");
ofstream cout("output.txt");
*/
int main() {
    cin >> s >> n;
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int len = 0, pos = 0;
    for (int l = 0, r = -1; l < (int) s.length(); ++l) {
        r = max(r, l - 1);
        while (r + 1 < (int) s.length()) {
            bool may = true;
            for (int i = 0; i < n; ++i) {
                bool tf = (r + 1 - (int) b[i].length() + 1 >= l);
                for (int k = 0; k < (int) b[i].length(); ++k)
                    if (b[i][k] != s[r + 1 - b[i].length() + 1 + k]) {
                        tf = 0;
                        break;
                    }
                if (tf) {
                    may = false;
                    break;
                }
            }
            if (may) {
                ++r;
            } else {
                break;
            }
        }
        if (r - l + 1 > len) {
            len = r - l + 1;
            pos = l;
        }
    }
    cout << len << " " << pos << endl;
    return 0;
}