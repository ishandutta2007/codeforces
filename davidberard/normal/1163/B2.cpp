#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 100100;
int n;
int a[NMAX];
int amt[NMAX]; // how many numbers have this many occurrences
int have[NMAX]; // how many of this number do we have
int nums = 0;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int ans = 0;
    set<pii> st;
    for(int i=1; i<=100000; ++i) {
        have[i] = 0;
    }
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        if(have[a[i]] == 0) {
            have[a[i]] = 1;
            ++amt[1];
            ++nums;
            if(amt[1] != 1) {
                st.erase(pii(amt[1]-1, 1));
            }
            st.emplace(amt[1], 1);
        } else {
            have[a[i]]++;
            st.erase(pii(amt[have[a[i]]-1], have[a[i]]-1));
            --amt[have[a[i]]-1];
            ++amt[have[a[i]]];
            st.emplace(amt[have[a[i]]], have[a[i]]);
        }
        if(amt[have[a[i]]] == 1 && amt[have[a[i]]-1] == nums-1) {
            ans = max(ans, i);
        }
        if(amt[have[a[i]]+1] == 1 && amt[have[a[i]]] == nums-1) {
            ans = max(ans, i);
        }
        /*
        if(amt[have[a[i]]] == amt[have[a[i]]-1]+1 && amt[have[a[i]]]+amt[have[a[i]]-1] == nums) {
            ans = max(ans, i);
        }
        if(amt[have[a[i]]+1] == amt[have[a[i]]]+1 && amt[have[a[i]]]+amt[have[a[i]]+1] == nums) {
            ans = max(ans, i);
        } */
        int mv = st.rbegin()->second;
        if((amt[1] == 1 && nums < 2) || (amt[1] == 1 && amt[mv] == nums-1) || (amt[mv] == nums && mv == 1)) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
    return 0;
}