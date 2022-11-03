#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 1e6;

vector<int> nums;

int ans[kMaxN + 1];
int pr[kMaxN + 1];

bool IsGood(int num)
{
    while (num > 0) {
        int c = num % 10;
        if (c != 0 && c != 1) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i <= kMaxN; ++i) {
        if (IsGood(i)) {
            nums.push_back(i);
        }
    }
    
    ans[0] = 0;
    for (int i = 1; i <= kMaxN; ++i) {
        ans[i] = i;
        pr[i] = 1;
        for (int j = 0; j < (int) nums.size(); ++j) {
            if (nums[j] <= i) {
                if (ans[i - nums[j]] + 1 < ans[i]) {
                    ans[i] = ans[i - nums[j]] + 1;
                    pr[i] = nums[j];
                }
            }
        }
    }
    
    int n;
    cin >> n;
    cout << ans[n] << endl;
    vector<int> prs;
    for (int x = n; x > 0; x -= pr[x]) {
        prs.push_back(pr[x]);
    }
    sort(prs.begin(), prs.end());
    for (int i = 0; i < ans[n]; ++i) {
        cout << prs[i] << " ";
    }
    cout << endl;
    
    return 0;
}