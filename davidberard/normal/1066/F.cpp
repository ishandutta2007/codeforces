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
typedef long double ld;

struct pii {
    int first, second;
    pii() {}
    pii(int a, int b) : first(a), second(b) {}
    bool operator < (const pii& o) const {
        if(max(first, second) != max(o.first, o.second)) {
            return max(first, second) < max(o.first, o.second);
        }
        if(first < second) {
            if(o.first > o.second) return true;
            return first < o.first;
        } else {
            if(o.first < o.second) return false;
            return second > o.second;
        }
    }
};

inline int dist(const pii& a, const pii& b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
}

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if(S == T) {
        T = (S=buf)+fread(buf, 1, 100000, stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
inline void read(int& x) {
    static char c;
    x = 0;
    for(c=get();c>'9'||c<'0';c=get());
    for(;c<='9'&&c>='0';c=get()) x=x*10+c-'0';
}

ll dp[200200][2], ord[200200];
int n;
pii orig[200200];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(n);
    for(int i=0; i<n; ++i) {
        read(orig[i].first);
        read(orig[i].second);
    }
    sort(orig, orig+n);
    int i = 0;
    pii l0(0, 0), l1(0, 0);
    for(int j=0; j<n; ++j) {
        pii t0, t1(-1, -1);
        t0 = orig[j];
        ++i;
        while(j<n && max(t0.first, t0.second) == max(orig[j].first, orig[j].second)) {
            ++j;
        }
        --j;
        t1 = orig[j];
        //cerr << " . " << t0.first << "," << t0.second << " " << t1.first << "," << t1.second << endl;
        dp[i][0] = dp[i-1][0] + dist(l0, t1);
        dp[i][0] = min(dp[i][0], dp[i-1][1] + dist(l1, t1));
        dp[i][0] += dist(t0, t1);

        dp[i][1] = dp[i-1][0] + dist(l0, t0);
        dp[i][1] = min(dp[i][1], dp[i-1][1] + dist(l1, t0));
        dp[i][1] += dist(t0, t1);
        l0 = t0, l1 = t1;
    }
    cout << min(dp[i][0], dp[i][1]) << endl;
    return 0;
}