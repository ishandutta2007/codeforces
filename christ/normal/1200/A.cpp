#include <bits/stdc++.h>
using namespace std;
bool open[10];
int main() {
    int n;
    scanf ("%d",&n); getchar();
    while (n--) {
        char c = getchar();
        if (c == 'L') {
            for (int i = 0; i < 10; i++) if (!open[i]) {open[i] = 1; break;}
        } else if (c == 'R') {
            for (int i = 9; i >= 0; i--) if (!open[i]) {open[i] = 1; break;}
        } else {
            open[c-'0'] = 0;
        }
    }
    for (int i = 0; i < 10; i++) printf ("%c",open[i]+'0');
    printf ("\n");
    return 0;
}