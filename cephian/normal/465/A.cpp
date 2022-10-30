#include <iostream>
#include <cstdio>

using namespace std;

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    char num[n];
    scanf("%s", num);
    int i = 0;
    for (; i < n; ++i) {
        if (num[i] == '0')
            break;
    }
    printf("%d", min(i+1, n));
    fflush(stdout);
    return 0;

}