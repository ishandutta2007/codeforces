//  228

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define MOD 1000000007
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>

int pow(int x, int y, int mod) {
    int temp;
    if (y == 0)
        return 1;

    temp = (pow(x, y / 2, mod)) % mod;

    if (y % 2 == 0)
        return (temp * temp) % mod;
    else
        return (((x * temp) % mod) * temp) % mod;
}

void add(string &str) {

    int n = str.length();
    int carry = 1;
    reverse(str.begin(), str.end());
    for(int i = 0; i < n; i ++) {

        if(str[i] == '1') {
            str[i] = '0';
            carry = 1;
        }

        else {
            str[i] = '1';
            carry = 0;
        }

        if(carry == 0)
            break;
    }

    if(carry == 1)
        str += '1';
    
    reverse(str.begin(), str.end());
}

void solve(int tno) {

    int n; cin >> n;

    int count = 0;
    string i = "1";
    
    while(stoi(i) <= n) {
        count ++;
        add(i);
    }

    cout << count << endl;
}

int32_t main() {

    FASTIO

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    // cin >> t;
    t = 1;
    for (int i = 1; i <= t; i ++)
        solve(i);
}