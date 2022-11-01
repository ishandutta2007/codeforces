#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define point pair <int, int>
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define re return
#define sz(a) (int)(a).size()
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()


using namespace std;


typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;


int n;
int a[200001];
long long pref[200001];
int cnt[200001];

long long solveClever() {
    //memset(pref, 0, sizeof(pref));
    int maxj = 1;
    For(q, 0, n) cnt[a[q]]++;
    For(i, 1, 2e5 + 1) {
        //cnt[i] = 1;
        //if (!cnt[i]) continue;
        int j = 1, lc = 0;
        while ((maxj + 1) * (maxj + 1) <= i) {
            maxj++;
        }
        j = maxj;
        int last = -1;
        For(k, 1, maxj + 1) {
            //last = i / k;
            if (cnt [i]>1000)pref[k] += (long long)(i/k - lc) * cnt[i];
            else pref [k]+=(i/k-lc)*cnt[i];
            lc = i/k;
        }
        last = maxj;
        pref[i + 1] += -cnt[i];
        while (j >= 1) {
            int k = i / (j + 1) + 1;
            if (cnt[i]>1000)
            pref[k] += (long long)(j - lc) * cnt[i];
            else
            pref [k]+=(j-lc)*cnt[i];
            lc = j;
            last = k;
            j--;
        }
    }
    long long b = 0;
    long long ans = 0;
    int last = 0;
    For(i, 1, 2e5 + 1) {
        if (!cnt[i])
            continue;
        while (last <= i) {
            b += pref[last];
            last++;
        }
        ans = max(ans, b * i);
    }
    return ans;
}


int main() {
    //iostream::sync_with_stdio(0), cin.tie(0);
    scanf("%d", &n);
    //cin >> n;
    for (int i = 0; i < n; i++) {
        //cin >> a[i];
        scanf("%d", &a[i]);
    }
    printf("%lld", solveClever());
    return 0;
}