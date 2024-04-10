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

int n;
int a[110];

int cnt[5][5];

int main() {
    cnt[1][1] = (1<<13);
    cnt[1][2] = (1<<9)+(1<<6)+(1<<1);
    cnt[1][3] = (1<<12)+(1<<2)+(1<<5)+(1<<8);
    cnt[2][1] = (1<<3)+(1<<7)+(1<<11);
    cnt[2][2] = (1<<13);
    cnt[2][3] = (1<<13);
    cnt[3][1] = (1<<10)+(1<<7)+(1<<4)+(1<<1);
    cnt[3][2] = (1<<13);
    cnt[3][3] = (1<<13);
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int lst = 0;
    int frame = 0;
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        if((cnt[lst][a[i]]&(1<<13))) {
            cout << "Infinite\n";
            return 0;
        }
        //cerr << " .. " << ans << " -> ";
        ans += __builtin_popcount(frame|cnt[lst][a[i]])-__builtin_popcount(frame);
        //cerr << ans << endl;
        frame = cnt[lst][a[i]];
        lst = a[i];
    }
    cout << "Finite\n";
    cout << ans << endl;

    return 0;
}