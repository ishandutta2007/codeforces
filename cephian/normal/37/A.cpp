#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int mx(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int N;
    scanf("%d", &N);
    map<int, int> vals;

    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++vals[tmp];
    }
    int tot = 0;
    int max = 0;
    for (map<int, int>::iterator it = vals.begin(); it != vals.end(); it++) {
        ++tot;
        max = mx(it->second, max);
    }
    printf("%d %d", max, tot);
}