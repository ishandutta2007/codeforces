#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 500100
#define MOD 1000000007

vector<char> v; // Stores the order.
string ft;
int n;

void chk(string s, int ind) {
    // From string s, remove all letters corresponding to v[i]. Then add this string to ft and recursively check
    // For next i, until i = n-1.
    if(ind == v.size()) return;
    forn(i, 0, s.length()) {
        ft +=s[i];
    }
    string temp;
    forn(i, 0, s.length()) {
        if(s[i]!=v[ind]) {
            temp += s[i];
        }
    }
    // forn(i, 0, temp.length()) {
    //     ft = ft + temp[i];
    // }
    chk(temp, ind + 1);
}

void solve() {
    string s;
    cin >> s;
    ft.clear();
    n = s.length();
    v.clear();
    map<char, int> m;
    for(int i = n-1; i >=0 ; i--) {
        if(m[s[i]]==0) {
            v.push_back(s[i]);
            m[s[i]] = 1;
        }
        else {
            m[s[i]]++;
        }
    }
    int x = v.size();
    reverse(v.begin(), v.end());
    // Number of operations = x.
    map<char, int> t;
    // t will store the number of occurences in ORIGINAL string.
    forn(i, 0, x) {
        t[v[i]] = m[v[i]]/(i + 1);
        if(m[v[i]]%(i + 1)!=0) {
            cout << -1 << endl;
            return;
        }
    }
    int t_len = 0; // the expected length of final string.
    for(auto i : t) {
        t_len += i.second;
    }
    string ans;
    map<char, int> check;
    forn(i, 0, t_len) {
        ans += s[i];
        check[s[i]]++;
        if(check[s[i]] > t[s[i]]) {
            cout << -1 << endl;
            return;
        }
    }
    // Now the string ans is the starting string. Create the ending string from it.
    // In the end, ft must equal s.
    chk(ans, 0);
    // cerr << ft << endl;
    forn(i, 0, n) {
        if(ft[i]!=s[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << " ";
    for(auto i : v) cout << i;
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
    {solve();}
    return 0;
}