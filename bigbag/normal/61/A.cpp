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

const int max_n = 111, inf = 111111111;

char s1[max_n];
char s2[max_n];
char ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(s1);
    gets(s2);
    for (int i = 0; i < strlen(s1); ++i) {
        if (s1[i] != s2[i]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}