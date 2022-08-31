#include <bits/stdc++.h> //
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n;
string s;
map<char,int> tmp;

void getpal(int val, char c = '-') {
    string ans, ans1;
    F0R(i,val/2) {
        while (tmp.begin()->s == 0) tmp.erase(tmp.begin());
        ans += tmp.begin()->f;
        tmp.begin()->s -= 2;
    }
    if (c == '-') {
        ans1 = ans; reverse(ans1.begin(),ans1.end());
        ans += ans1;
    } else {
        ans1 = ans; reverse(ans1.begin(),ans1.end());
        ans += c;
        ans += ans1;
    }
    cout << ans << " ";
}

void test(int x) {
    int z = 0;
    for (auto a: tmp) if (a.s % 2 != 0) z++;
    
    // each part has even
    if (n/x % 2 == 0) {
        if (z > 0) return;
        cout << x << "\n";
        F0R(i,x) getpal(n/x);
        exit(0);
    }
    
    // each part has odd
    if (n/x % 2 == 1) {
        if (z > x) return;
        int x1 = x;
        cout << x << "\n";
        vector<char> need;
        for (auto& a: tmp) if (a.s&1) {
            need.pb(a.f);
            a.s --, x --;
        }
        for (auto& a: tmp) while (x > 0 && a.s > 0) {
            need.pb(a.f), need.pb(a.f);
            a.s -= 2; x -= 2;
        }
        F0R(i,x1) getpal(n/x1,need[i]);
        exit(0);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> s;
	for (char c: s) tmp[c] ++;
	FOR(i,1,n+1) if (n % i == 0) test(i);
}

// read!
// ll vs. int!