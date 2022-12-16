#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int TT;
char s[110];
int cnt[26];

const int MAX = 1e6;

void tfill(const vector<int>& opt, vector<int>& have, int u) {
    for(int i=0; i<have[opt[u]]; ++i) {
        cout << (char) (opt[u]+'a');
    }
}

void solve(vector<int>& opt, vector<int>& have) {
    if(opt.size() == 1) {
        tfill(opt, have, 0);
        return;
    }
    if(opt.size() == 2) {
        tfill(opt, have, 0);
        tfill(opt, have, 1);
        return;
    }
    if(opt.size() == 3) {
        int a=0, b=2;
        if(abs(opt[1]-opt[0]) <= 1) swap(a, b);
        tfill(opt, have, 1);
        tfill(opt, have, a);
        tfill(opt, have, b);
        return;
    }
    if(opt.size() == 4) {
        tfill(opt, have, 2);
        tfill(opt, have, 0);
        tfill(opt, have, 3);
        tfill(opt, have, 1);
        return;
    }
    if(opt.size()%2) {
        tfill(opt, have, opt.size()-1);
        opt.pop_back();
    } else {
        tfill(opt, have, 0);
        opt.erase(opt.begin());
    }
    solve(opt, have);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> TT;
    for(int tt=1; tt<=TT; ++tt) {
        cin >> (s+1);
        int n = strlen(s+1);
        vector<int> have(26, 0);
        int uniq = 0;
        vector<int> opt;
        for(int i=1; i<=n; ++i) {
            if(have[s[i]-'a']++ == 0) {
                opt.push_back(s[i]-'a');
                ++uniq;
            }
        }
        int len = 0;
        int t =0;
        for(int i=0; i<26; ++i) {
            if(have[i]) {
                len = max(len, ++t);
            } else {
                t = 0;
            }
        }
        if(len == uniq && (uniq == 2 || uniq == 3)) {
            cout << "No answer" << endl;
            continue;
        }
        sort(opt.begin(), opt.end());
        solve(opt, have);
        cout << endl;
    }
    return 0;
}