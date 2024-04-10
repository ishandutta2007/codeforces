#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
map <string, int> m;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (!m.count(s)) {
            printf("OK\n");
            m[s] = 1;
        } else {
            cout << s;
            printf("%d\n", m[s]++);
        }
    }
    return 0;
}