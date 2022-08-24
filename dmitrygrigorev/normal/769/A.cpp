#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define int int64_t
#define all(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair

int32_t main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    sort(all(nums));
    cout << nums[(n - 1) / 2] << endl;

    return 0;
}