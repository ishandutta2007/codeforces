#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 2002000;
int len[N*2-1];

void manacher(const string& str) {
    int n = str.size();
    len[0] = 1;
    for (int i = 1, j = 0; i < (n<<1)-1; ++i) {
        int p = i>>1, q = i-p, r = ((j+1)>>1) + len[j] - 1;
        len[i] = r<q ? 0 : min(r-q+1, len[(j<<1)-i]);
        while (p > len[i] - 1 && q + len[i] < n && str[p - len[i]] == str[q + len[i]]) {
            ++len[i];
        }
        if (q + len[i] - 1 > r) {
            j = i;
        }
    }
    for (int i=0; i<n*2-1; ++i) {
        len[i] = (i%2) ? len[i]*2 : (len[i]-1)*2+1;
    }
}

const ll MOD = 51123987;

int a[N], b[N], start[N], finish[N];
int n;
string s;

int d2(int x) {
    if (x >= 0) return x/2;
    return (x-1)/2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    manacher(s);

    ll ans = 0;
    ll total = 0;
    for (int i=0; i<n*2-1; ++i) {
        int j = i/2;
        a[j-d2(len[i]-1)]++;
        a[j+1]--;
        //cerr << " : " << (j-d2(len[i]-1)) << " to " << j+1 << endl;

        int k = (i+1)/2;
        b[k+d2(len[i]-1)]++;
        b[k-1]--;
        //cerr << "! total += " << (len[i]+1)/2 << endl;
        total += (len[i]+1)/2;
    }
    start[0] = a[0];
    for (int i=1; i<n; ++i) {
        start[i] = start[i-1]+a[i];
    }
    finish[n] = 0;
    for (int i=n-1; i>=0; --i) {
        finish[i] = finish[i+1]+b[i];
    }
    ll fs = 0;
    for (int i=0; i<n; ++i) {
        //cerr << " " << i << " : s " << start[i] << " f " << finish[i] << " : " << fs*start[i] << endl;
        ans += fs*start[i]%MOD;
        fs = (fs+finish[i])%MOD;
    }


    //cerr << "! total " << total << endl;
    total %= MOD;

    cout << (MOD+((total)*(total-1)/2)%MOD - ans%MOD)%MOD << "\n";
    return 0;
}