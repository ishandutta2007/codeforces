#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    vector<int> sum(2);
    vector<int> cnt(2);
    for (int x = 0; x < n; x++)
    {
        if (s[x] != '?')
            sum[x < n / 2] += s[x] - '0';
        else
            cnt[x < n / 2]++;
    }
    if (sum[0] > sum[1])
        swap(sum[0], sum[1]), swap(cnt[0], cnt[1]);
    if (cnt[0] < cnt[1])
        return 0 * printf("Monocarp\n");
    int diff = cnt[0] - cnt[1];
    int sum_diff = sum[1] - sum[0];
    assert(diff % 2 == 0);
    diff /= 2;
    int can_add = diff * 9;
    if (can_add == sum_diff)
        return 0 * printf("Bicarp\n");
    else
        printf("Monocarp\n");
}