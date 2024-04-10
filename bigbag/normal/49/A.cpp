#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

char s[max_n], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(s);
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            ans = s[i];
        }
    }
    if (ans == 'a' || ans == 'e' || ans == 'i' || ans == 'o' || ans == 'u' || ans == 'y' || ans == 'A' || ans == 'E' || ans == 'I' || ans == 'O' || ans == 'U' || ans == 'Y') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}