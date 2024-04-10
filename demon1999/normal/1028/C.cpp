#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

int xl[200000], xr[200000], yl[200000], yr[200000];
int qxl[200000], qxr[200000], qyl[200000], qyr[200000];
int n;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    qxl[0] = qyl[0] = -int(1e9);
    qxr[0] = qyr[0] = int(1e9);
    forn (i, n) {
        cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
        qxl[i + 1] = max(xl[i], qxl[i]);
        qyl[i + 1] = max(yl[i], qyl[i]);
        qxr[i + 1] = min(xr[i], qxr[i]);
        qyr[i + 1] = min(yr[i], qyr[i]);
    }
    int sxl, syl, sxr, syr;
    sxl = syl = -int(1e9);
    sxr = syr = int(1e9);
    for (int i = n - 1; i >= 0; i--) {
        if (max(sxl, qxl[i]) <= min(sxr, qxr[i]) && 
            max(syl, qyl[i]) <= min(syr, qyr[i])) {
            cout << max(sxl, qxl[i]) << " " << max(syl, qyl[i]) << "\n";
        return 0;
        }
        sxl = max(xl[i], sxl);
        syl = max(yl[i], syl);
        sxr = min(xr[i], sxr);
        syr = min(yr[i], syr);
    }
    return 0;
}