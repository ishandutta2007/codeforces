#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> sell;
    int n, v;
    scanf("%d %d", &n, &v);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int tmp;
            scanf("%d", &tmp);
            if (v > tmp
                    && (sell.size() == 0 || sell[sell.size() - 1] != i + 1)) {
                sell.push_back(i + 1);
            }
        }
    }
    printf("%d\n", sell.size());
    for (unsigned int i = 0; i < sell.size(); ++i) {
        printf("%d", sell[i]);
        if (i == sell.size() - 1)
            printf("\n");
        else
            printf(" ");
    }
}