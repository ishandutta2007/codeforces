#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll N, H;

bool possible(ll w) {
    if(w < H) return false;
    ll x = (w-H)/2+H;
    ll amt= (H*(H+1)/2 + (x-H)*H*2 + (x-H)*(x-H));
    if((w-H)%2 == 1) {
        amt += x;
    }
    return amt >= N;
}

int bs() {
    ll l = H, r = 2e9;
    while(l < r-1) {
        ll m = (l+r+1)/2;
        if(possible(m)) {
            r = m-1;
        } else {
            l = m;
        }
    }
    if(possible(l)) return l;
    else if(possible(l+1)) return l+1;
    return l+2;
}

bool isEasyPossible(ll x) {
    if( x <= 0 ) return false;
    //cerr << "x = " << x << " -> " << (x*(x+1)/2) << endl;
    return ( N <= x*(x+1)/2 );
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N >> H;

    if(H > 2e9 || (H+1)*H/2 > N) {
        // fill with no peak
        ll mguess = sqrt(N*2)-2;
        for(int i=mguess;i < mguess+100;++i) {
            if(isEasyPossible(i)) {
                cout << i << endl;
                return 0;
            }
        }
        assert(false);
    }
    cout << bs() << endl;
    
    
    return 0;
}