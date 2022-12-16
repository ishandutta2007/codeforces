#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 1001000;

int n, m;
int a[NMAX];
int amt[50];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    for(int i=0;i<m;++i) {
        int k;
        cin >> k;
        ++ amt[k];
    }
    int ans = 0;
    for(int p=0;p<30;++p) {
        int i;
        for(i=p;i<30 && amt[p];++i) {
        for(int j=0;j<n;++j) {
            //cerr << " " << ((a[j])>>i) << " " << i << endl;
            if((a[j]>>i)&1) {
                int x = 1<<(i-p);
                int t = min(x, amt[p]);
                //cerr << " .. " << t << endl;
                ans += t;
                amt[p] -= t;
                a[j] -= t*(1<<p);
            }
        }
        }
        if(i == 30) break;
    }
    cout << ans << endl;
    return 0;
}