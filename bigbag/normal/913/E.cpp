#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 266, inf = 1011111111;

const string ans[] = {"!x&x","x&y&z","!z&x&y","x&y","!y&x&z","x&z","!y&x&z|!z&x&y","(y|z)&x","!y&!z&x","!y&!z&x|x&y&z","!z&x","!z&x|x&y","!y&x","!y&x|x&z","!(y&z)&x","x","!x&y&z","y&z","!x&y&z|!z&x&y","(x|z)&y","!x&y&z|!y&x&z","(x|y)&z","!x&y&z|!y&x&z|!z&x&y","(x|y)&z|x&y","!x&y&z|!y&!z&x","!y&!z&x|y&z","!x&y&z|!z&x","!z&x|y&z","!x&y&z|!y&x","!y&x|y&z","!(y&z)&x|!x&y&z","x|y&z","!x&!z&y","!x&!z&y|x&y&z","!z&y","!z&y|x&y","!x&!z&y|!y&x&z","!x&!z&y|x&z","!y&x&z|!z&y","!z&y|x&z","!(!x&!y|x&y|z)","!(!x&!y|x&y|z)|x&y&z","!z&(x|y)","!z&(x|y)|x&y","!x&!z&y|!y&x","!x&!z&y|!y&x|x&z","!y&x|!z&y","!z&y|x","!x&y","!x&y|y&z","!(x&z)&y","y","!x&y|!y&x&z","!x&y|x&z","!(x&z)&y|!y&x&z","x&z|y","!x&y|!y&!z&x","!x&y|!y&!z&x|y&z","!x&y|!z&x","!z&x|y","!x&y|!y&x","!x&y|!y&x|x&z","!(x&z)&y|!y&x","x|y","!x&!y&z","!x&!y&z|x&y&z","!x&!y&z|!z&x&y","!x&!y&z|x&y","!y&z","!y&z|x&z","!y&z|!z&x&y","!y&z|x&y","!(!x&!z|x&z|y)","!(!x&!z|x&z|y)|x&y&z","!x&!y&z|!z&x","!x&!y&z|!z&x|x&y","!y&(x|z)","!y&(x|z)|x&z","!y&z|!z&x","!y&z|x","!x&z","!x&z|y&z","!x&z|!z&x&y","!x&z|x&y","!(x&y)&z","z","!(x&y)&z|!z&x&y","x&y|z","!x&z|!y&!z&x","!x&z|!y&!z&x|y&z","!x&z|!z&x","!x&z|!z&x|x&y","!x&z|!y&x","!y&x|z","!(x&y)&z|!z&x","x|z","!(!y&!z|x|y&z)","!(!y&!z|x|y&z)|x&y&z","!x&!y&z|!z&y","!x&!y&z|!z&y|x&y","!x&!z&y|!y&z","!x&!z&y|!y&z|x&z","!y&z|!z&y","!y&z|!z&y|x&y","!(!x&!y|x&y|z)|!x&!y&z","!(!x&!y|x&y|z)|!x&!y&z|x&y&z","!x&!y&z|!z&(x|y)","!x&!y&z|!z&(x|y)|x&y","!x&!z&y|!y&(x|z)","!x&!z&y|!y&(x|z)|x&z","!y&(x|z)|!z&y","!y&z|!z&y|x","!x&(y|z)","!x&(y|z)|y&z","!x&z|!z&y","!x&z|y","!x&y|!y&z","!x&y|z","!(x&y)&z|!z&y","y|z","!x&(y|z)|!y&!z&x","!x&(y|z)|!y&!z&x|y&z","!x&(y|z)|!z&x","!x&z|!z&x|y","!x&(y|z)|!y&x","!x&y|!y&x|z","!x&y|!y&z|!z&x","x|y|z","!(x|y|z)","!(x|y|z)|x&y&z","!(!x&y|!y&x|z)","!(x|y|z)|x&y","!(!x&z|!z&x|y)","!(x|y|z)|x&z","!(!x&y|!y&x|z)|!y&x&z","!(x|y|z)|(y|z)&x","!y&!z","!y&!z|x&y&z","!(!x&y|z)","!y&!z|x&y","!(!x&z|y)","!y&!z|x&z","!(!x&y|z)|!y&x","!y&!z|x","!(!y&z|!z&y|x)","!(x|y|z)|y&z","!(!x&y|!y&x|z)|!x&y&z","!(x|y|z)|(x|z)&y","!(!x&z|!z&x|y)|!x&y&z","!(x|y|z)|(x|y)&z","!(!x&y|!y&x|z)|!x&y&z|!y&x&z","!(x|y|z)|(x|y)&z|x&y","!x&y&z|!y&!z","!y&!z|y&z","!(!x&y|z)|!x&y&z","!(!x&y|z)|y&z","!(!x&z|y)|!x&y&z","!(!x&z|y)|y&z","!(!x&y|z)|!x&y&z|!y&x","!y&!z|x|y&z","!x&!z","!x&!z|x&y&z","!(!y&x|z)","!x&!z|x&y","!x&!z|!y&x&z","!x&!z|x&z","!(!y&x|z)|!y&x&z","!(!y&x|z)|x&z","!(x&y|z)","!(x&y|z)|x&y&z","!z","!z|x&y","!x&!z|!y&x","!(x&y|z)|x&z","!y&x|!z","!z|x","!(!y&z|x)","!x&!z|y&z","!(!y&x|z)|!x&y","!x&!z|y","!(!y&z|x)|!y&x&z","!(!y&z|x)|x&z","!(!y&x|z)|!x&y|!y&x&z","!x&!z|x&z|y","!x&y|!y&!z","!(x&y|z)|y&z","!x&y|!z","!z|y","!(!x&!y&z|x&y)","!x&!z|!y&x|y&z","!x&y|!y&x|!z","!z|x|y","!x&!y","!x&!y|x&y&z","!x&!y|!z&x&y","!x&!y|x&y","!(!z&x|y)","!x&!y|x&z","!(!z&x|y)|!z&x&y","!(!z&x|y)|x&y","!(x&z|y)","!(x&z|y)|x&y&z","!x&!y|!z&x","!(x&z|y)|x&y","!y","!y|x&z","!y|!z&x","!y|x","!(!z&y|x)","!x&!y|y&z","!(!z&y|x)|!z&x&y","!(!z&y|x)|x&y","!(!z&x|y)|!x&z","!x&!y|z","!(!z&x|y)|!x&z|!z&x&y","!x&!y|x&y|z","!x&z|!y&!z","!(x&z|y)|y&z","!(!x&!z&y|x&z)","!x&!y|!z&x|y&z","!x&z|!y","!y|z","!x&z|!y|!z&x","!y|x|z","!(x|y&z)","!(x|y&z)|x&y&z","!x&!y|!z&y","!(x|y&z)|x&y","!x&!z|!y&z","!(x|y&z)|x&z","!(!y&!z&x|y&z)","!x&!y|!z&y|x&z","!((x|y)&z|x&y)","!((x|y)&z|x&y)|x&y&z","!x&!y|!z","!x&!y|!z|x&y","!x&!z|!y","!x&!z|!y|x&z","!y|!z","!y|!z|x","!x","!x|y&z","!x|!z&y","!x|y","!x|!y&z","!x|z","!x|!y&z|!z&y","!x|y|z","!x|!y&!z","!x|!y&!z|y&z","!x|!z","!x|!z|y","!x|!y","!x|!y|z","!(x&y&z)","!x|x"};

int n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> s;
        int mask = 0;
        for (int i = 0; i < 8; ++i) {
            mask += (1 << i) * (s[7 - i] - '0');
        }
        cout << ans[mask] << "\n";
    }
    return 0;
}