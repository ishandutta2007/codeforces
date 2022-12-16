#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 5050;

vector<int> at[NMAX];
int pre[NMAX];
int mlen[NMAX];
int xtra[NMAX];
int n, m;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;++i) {
        int a, b;
        cin >> a >> b;
        at[a].push_back(b);
    }
    int p = 0;
    for(int i=1;i<=n;++i) {
            mlen[i] = n;
            for(auto& j : at[i]) {
                int tv = j-i;
                if(tv < 0) tv +=n;
                mlen[i] = min(tv, mlen[i]);
            }
    }

    for(int i=1;i<=n;++i) {
        ll bst = 0;
        for(int j=0;j<n;++j) {
            int ind = ((j+i-1)%n+1);
            if(at[ind].size() == 0) continue;
            ll tv = (((ll) at[ind].size()-1)*n+j+mlen[ind]);
            if(tv > bst) {
                bst = tv;
                //cerr << "! from " << ind << " we improve to " << bst << " at " << i << endl;
                //cerr << "! " << ((ll) at[ind].size()-1)*n << " " << j << " " << mlen[ind] << endl;
            }
        }
        cout << bst << " ";
    }
    cout << endl;

    
    return 0;
}