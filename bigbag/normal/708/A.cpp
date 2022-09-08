#include <map>
#include <set>
#include <stack>
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

const int max_n = 111111, inf = 1111111111;

int n, poz;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    poz = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            poz = i;
            break;
        }
    }
    if (poz == -1) {
        s[n - 1] = 'z';
        printf("%s\n", s);
        return 0;
    }
    int last = n;
    for (int i = poz + 1; i < n; ++i) {
        if (s[i] == 'a') {
            last = i;
            break;
        }
    }
    for (int i = poz; i < last; ++i) {
        --s[i];
    }
    printf("%s\n", s);
    return 0;
}