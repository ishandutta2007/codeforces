#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 1000001;
char s[N];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    int mn = 26;
    for (int i = 0; i < len; i ++) {
        if (mn < s[i] - 'a')
            printf("Ann\n");
        else
            printf("Mike\n");
        mn = min(mn, s[i] - 'a');
    }
    return 0;
}