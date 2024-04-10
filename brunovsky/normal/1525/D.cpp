#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
namespace gnu = __gnu_pbds;

template <typename T, typename CompareFn = less<T>>
using ordered_set = gnu::tree<T, gnu::null_type, CompareFn, gnu::rb_tree_tag,
                              gnu::tree_order_statistics_node_update>;

#define long int64_t

// *****

int dp[5001][5001];

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> ones, zeros;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] == 1 ? ones.push_back(i) : zeros.push_back(i);
    }

    int O = ones.size(), Z = zeros.size();
    assert(O <= Z);
    // dp[i][z]: min answer if we move [1..i] up to [1..z]
    memset(dp, 0x7f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));

    for (int i = 1; i <= O; i++) {
        int one = ones[i - 1];
        for (int z = 1; z <= Z; z++) {
            int zero = zeros[z - 1];
            dp[i][z] = min(dp[i][z - 1], dp[i - 1][z - 1] + abs(one - zero));
            // cout << setw(3) << (dp[i][z] >= INT_MAX / 8 ? "--"s : to_string(dp[i][z]));
        }
        // cout << endl;
    }

    return *min_element(dp[O], dp[O] + Z + 1);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}