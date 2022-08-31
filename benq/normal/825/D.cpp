#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

string s,t;
ll oc[27], oc2[27];

void solve(int ans) {
    ll z[26];
    vector<char> todo;
    F0R(i,26) {
        z[i] = oc2[i]*ans;
        F0R(j,z[i]-oc[i]) todo.pb('a'+i);
    }
    F0R(i,s.length()) if (s[i] == '?') {
        if (todo.size()) {
            s[i] = todo[todo.size()-1];
            todo.erase(todo.end()-1);
        } else s[i] = 'a';
    }
    cout << s;
}

bool ok(int ans) {
    ll z[26], need = 0;
    F0R(i,26) {
        z[i] = oc2[i]*ans;
        need += max(z[i]-oc[i],0LL);
    }
    return need <= oc[26];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    F0R(i,s.length()) {
        if (s[i] == '?') oc[26] ++;
        else oc[s[i]-'a'] ++;
    }
    F0R(i,t.length()) {
        if (t[i] == '?') oc2[26] ++;
        else oc2[t[i]-'a'] ++;
    }
    int ans = 0;
    while (ok(ans+1)) ans ++;
    solve(ans);
}