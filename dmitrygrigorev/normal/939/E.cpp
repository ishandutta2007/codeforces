#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
double EPS = 0.00000001;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cout.precision(30);
    cin >> n;
    vector<int> v, pref;
    pref.push_back(0);
    double ans = 0;
    for (int i=0; i < n; i++){
        int t;
        cin >> t;
        if (t == 1){
            int N;
            cin >> N;
            pref.push_back(pref.back() + N);
            int L = -1;
            int R = ((int) v.size()) - 1;
            while (R - L > 1){
                int M = (L+R) / 2;
                double on = (double) (N+pref[M+1]) / (double) (M+2);
                double tw = (double) (N+pref[M+2]) / (double) (M+3);
                if (tw - on < EPS) L = M;
                else R = M;
            }
            L++;
            //cout << L << endl;
            ans = max(ans, (double) N - (double) (N + pref[L+1]) / (double) (L+2));
            v.push_back(N);
        }
        else cout << ans << endl;
    }
}