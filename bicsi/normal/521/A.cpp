#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int pw(int b, int e) {
    int r = 1;
    for(int i=1; i<=e; i<<=1) {
        if(e & i) {
            r = 1LL * r * b % MOD;
        }
        b = 1LL * b * b % MOD;
    }
    return r;
}

int Cnt[256];

int main() {
    int n; char c;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>c;
        Cnt[c]++;
    }

    int best = 0, bcc = 0;

    for(int i=1; i<256; i++) {
        if(best < Cnt[i]) {
            best = Cnt[i];
            bcc = 0;
        }
        if(best == Cnt[i]) {
            bcc++;
        }
    }

//    cout<<best<<" "<<bcc<<'\n';

    cout << pw(bcc, n);

    return 0;
}