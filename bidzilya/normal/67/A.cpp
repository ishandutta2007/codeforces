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

const int max_n = 1e3 + 100;

int n;
string s;
int a[max_n];

int main() {
    cin >> n >> s;
    a[0] = 1;
    for (int i = 1; i < n; ++i)
        if (s[i - 1] == 'L') {
            if (a[i - 1] == 1) {
                ++a[i - 1];
                int j = i - 1;
                while (j > 0) {
                    if (s[j - 1] == 'R') break;
                    if (s[j - 1] == 'L') {
                        if (a[j - 1] == a[j]) {
                            ++a[j - 1];
                            --j;
                        } else
                            break;
                    } else {
                        ++a[j - 1];
                        --j;
                    }
                }
            }
            a[i] = 1;
        } else if (s[i - 1] == '=') {
            a[i] = a[i - 1];
        } else if (s[i - 1] == 'R') {
            a[i] = a[i - 1] + 1;
        }
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}