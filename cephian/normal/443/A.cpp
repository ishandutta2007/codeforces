#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cctype>

using namespace std;

int main() {
    bool lets[26];
    std::fill(lets, lets + 26, false);
    for (;;) {
        char c = getchar();
        if (isalpha(c)) {
            lets[c - 'a'] = true;
        } else if (c == '}')
            break;
    }
    int amt = 0;
    for (int i = 0; i < 26; ++i) {
        if (lets[i])
            ++amt;
    }
    printf("%d", amt);
    return 0;
}