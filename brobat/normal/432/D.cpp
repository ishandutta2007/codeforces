#include <bits/stdc++.h>
using namespace std;
#define forn(i, a, n) for (int i = a; i < n; i++)

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector <int> z = z_function(s);
    int n = z.size();
    vector <int> v;
    forn(i, 1, n) {
        if(i + z[i] == n) v.push_back(z[i]);
    }
    int x = v.size();
    sort(z.begin(), z.end());
    vector <int> c;
    int num_times = 0;
    int i = 0; // i -> 0 to n - 1
    int j = 0; // j -> 0 to x - 1
    while(i < n && j < x) {
        if(i==n-1) {
            c.push_back(num_times);
            j++;
        }
        else {
            if(z[n-i-1] >= v[j]) {
                num_times++;
                i++;
            }
            else {
                c.push_back(num_times);
                j++;
            }
        }
    }
    cout << x+1 << endl;
    forn(k, 0, x) {
        cout << v[x-k-1] << " " << c[x-k-1]+1 << endl;
    }
    cout << n << " " << 1;
    return 0;
}