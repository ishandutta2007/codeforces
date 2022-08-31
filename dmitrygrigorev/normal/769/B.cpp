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
    vector<pair<int, int>> answer, nums(n);
    for (int i = 0; i < n; ++i) {
        int inp;
        cin >> inp;
        nums[i] = mp(-inp, i);
    }

    if (!nums[0].first)
        cout << -1 << endl;
    else {
        vector<bool> know(n, false);
        know[0] = true;
        nums[0].first++;
        sort(all(nums));
        if (nums[0].second) {
            answer.pb(mp(1, nums[0].second + 1));
            know[nums[0].second] = true;
        }
        else {
            nums[0].first--;
        }

        /*for (auto &elem : nums)
            cout << elem.first << " " << elem.second << endl;
        for (bool elem : know)
            cout << elem << " ";
        cout << endl;*/

        int input = 1, output = 0;
        while (input < n && know[nums[output].second]) {
            if (know[nums[input].second])
                input++;
            else {
                while (input < n && nums[output].first) {
                    if (know[nums[input].second])
                        input++;
                    else {
                        answer.pb(mp(nums[output].second + 1, nums[input].second + 1));
                        know[nums[input].second] = true;
                        input++;
                        nums[output].first++;
                    }
                }
                output++;
            }
        }

        if (input < n)
            cout << -1 << endl;
        else {
            cout << answer.size() << endl;
            for (auto &elem : answer)
                cout << elem.first << " " << elem.second << endl;
        }
    }

    return 0;
}