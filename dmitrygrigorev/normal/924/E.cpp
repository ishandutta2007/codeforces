#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int K = 10001;
signed main(){
   // freopen("1.txt", "r", stdin);
    int n, l, r, ans=0;
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];
    vector<int> bad, good;
    for (int i=0; i < n; i++){
        if (b[i] == 0) bad.push_back(a[i]);
        else good.push_back(a[i]);
    }
    if (good.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(good.begin(), good.end());
    int S=0;
    for (int i=0; i < good.size(); i++) S += good[i];
    bool knapbad[K], knapgood[K];
    for (int i=0; i < K; i++) knapbad[i] = false;
    for (int i=0; i < K; i++) knapgood[i] = false;
    knapbad[0] = true;
    knapgood[0] = true;
    for (int i=0; i < bad.size(); i++){
        for (int j=K-1; j >= bad[i]; j--) knapbad[j] |= knapbad[j - bad[i]];
    }
    int pref[K+1];
    pref[0] = 0;
    for (int i=1; i <= K; i++) pref[i] = pref[i-1] + knapbad[i-1];
    vector<vector<int> > close(good.size());
    int INF = 1e9;
    close[good.size() - 1].push_back(0);
    for (int i=good.size() - 1; i >= 0; i--){
        for (int j=K-1; j >= good[i]; j--){
            if (!knapgood[j] && knapgood[j - good[i]]){
                if (i!=0) close[i-1].push_back(j);
                knapgood[j] = true;
            }
        }
    }
    for (int i=l; i <= r; i++) if (knapgood[i] && i != S) ans = max(ans, (int) 1);
    int Kn[K];
    for (int i=0; i < K; i++) Kn[i] = -INF;
    Kn[0] = 0;
    for (int i=0; i < good.size(); i++){
        for (int j=K-1; j >= good[i]; j--){
            Kn[j] = max(Kn[j], Kn[j-good[i]]+1);
        }
        for (int j=0; j < close[i].size(); j++){
            int N = close[i][j];
            for (int p=0; p < K; p++){
                if (Kn[p] < 0) continue;
                int L = max((int) 0, l - N), R = r-N-p;
                if (L > R) continue;
                if (pref[R+1] - pref[L] == 0) continue;
                if (N+p == S) ans = max(ans, Kn[p]);
                else ans = max(ans, Kn[p]+1);
            }
        }
    }
    cout << ans;
}