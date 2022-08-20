#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,d, m = 0, cur = 0; cin >> n >> d;
    F0R(i,d) {
        string s; cin >> s;
        bool f = 0;
        F0R(i,s.length()) if (s[i] == '0') {
            f = 1;
            break;
        }
        if (f) cur++;
        else {
            m = max(m,cur);
            cur = 0;
        }
    }
    cout << max(m,cur);
}