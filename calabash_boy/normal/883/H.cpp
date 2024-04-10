#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+9;
const int M = 123;

int n, c1;
int c[M];
char s[N];
stack<char> st[N], to;

void print(int i, int len) {
    for (int j = 0; j < len / 2; j++) {
        s[j] = s[len - j - 1] = st[i].top();
        st[i].pop();
    }
    if (!st[i].empty()) s[len / 2] = st[i].top();
    for (int j = 0; j < len; j++) printf("%c", s[j]);
    printf(" ");
}

int main() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) c[ s[i] ]++;
    for (int i = 0; i < M; i++) {
        if (c[i] & 1) c1++;
    }
    if (0 == c1) {
        for (int i = 0; i < M; i++) if (c[i]) {
            while (c[i]) c[i] -= 2, st[0].push(i);
        }
        printf("%d\n", 1);
        print(0, n);
        return 0;
    }
    for (int i = c1; i < n; i++) if (0 == (n % i)) {
        if (0 == ((n / i) & 1)) continue;
        if ((i - c1) & 1) continue;
        
        for (int j = 0, k = 0; j < c1 && k < M; k++) {
            if (c[k] & 1) c[k]--, st[j++].push(k); 
        }
        for (int j = c1, k = 0; j < i && k < M; k++) {
            while (c[k] && j < i) c[k] -= 2, st[j++].push(k), st[j++].push(k);
        }
        for (int j = 0; j < M; j++) if (c[j]) {
            while (c[j]) c[j] -= 2, to.push(j);
        }
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < n / i / 2; k++) {
                st[j].push(to.top());
                to.pop();
            }
        }
        printf("%d\n", i);
        for (int j = 0; j < i; j++) print(j, n / i);
        return 0;
    }
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%c%c", s[i], " \n"[i == n - 1]);
}