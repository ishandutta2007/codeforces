#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    int start = 0, end = n - 1;
    int ser = 0, dim = 0;
    bool who = false;
    while (end >= start) {
        int val;
        if (nums[end] > nums[start]) {
            val = nums[end];
            --end;
        } else {
            val = nums[start];
            ++start;
        }
        if (who)
            ser += val;
        else
            dim += val;
        who = !who;
    }
    printf("%d %d", dim, ser);
}