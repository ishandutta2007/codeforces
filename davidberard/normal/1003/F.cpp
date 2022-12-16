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

int dp[303][303];
bool eq[303][303];
string str[303];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> str[i];
    }
    for(int i=1; i<=n; ++i) {
        for(int j=i; j<=n; ++j) {
            if(str[i] == str[j]) {
                eq[i][j] = 1;
                eq[j][i] = 1;
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            dp[i][j] = min(j-i, n-j+1);
            for(int k=0; k<j-i && k+j<=n; ++k) {
                if(!eq[i+k][j+k]) {
                    dp[i][j] = k;
                    break;
                }
            }
        }
    }
    int best = 0;
    for(int i=1; i<=n; ++i) {
        for(int l=1; l+i-1<=n; ++l) {
            int cnt = 0;
            for(int j=i+1; j<=n; ++j) {
                if(dp[i][j] >= l) {
                    ++cnt;
                    j+=l-1;
                }
            }
            if(cnt) {
                int x = 0;
                for(int j=i; j<i+l; ++j) {
                    x += str[j].size()+1;
                }
                --x;
                best = max(best, (x-l)*(cnt+1));
            }
        }
    }
    int total = -1;
    for(int i=1; i<=n; ++i) {
        total += str[i].size()+1;
    }
    cout << total-best << endl;
    return 0;
}