#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 1)
            a.push_back(i);
        else if (tmp == 2)
            b.push_back(i);
        else
            c.push_back(i);
    }
    int nums = min(a.size(), min(b.size(), c.size()));
    printf("%d\n", nums);
    for (int i = 0; i < nums; ++i) {
        printf("%d %d %d\n", a[i] + 1, b[i] + 1, c[i] + 1);
    }
    return 0;
}