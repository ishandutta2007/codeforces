#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int NMAX = 300300;

int n;
char s[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    cin >> (s+1);
    
    int seen[26];
    memset(seen, 0, sizeof seen);
    for(int i=1; i<=n; ++i) {
        seen[s[i]-'a'] = i;
        for(int j=s[i]-'a'+1; j<26; ++j) {
            if(seen[j]) {
                cout << "YES\n" << seen[j] << " " << i << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}