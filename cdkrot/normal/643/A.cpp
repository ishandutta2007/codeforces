#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        vector<int> nums(n + 1, 0);
        int mx = 0;
        for (int j = i; j < n; j++) {
            nums[t[j]]++;
            if (make_pair(nums[t[j]], -t[j]) > make_pair(nums[mx], -mx))
                mx = t[j];
            ans[mx]++;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}