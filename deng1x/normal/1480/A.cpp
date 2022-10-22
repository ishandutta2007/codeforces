//
// Created by Junjie Wu on 2021/2/20.
//

#include <bits/stdc++.h>

char s[100];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        for (int i = 0; s[i]; ++i) {
            if (!(i & 1)) {
                // Alice
                if (s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            } else {
                // Bob
                if (s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }
        }
        printf("%s\n", s);
    }
    return 0;
}