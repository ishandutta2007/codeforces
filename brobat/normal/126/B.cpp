#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    auto z = z_function(s);
    int n = z.size();
    vector <int> v;
    for(int i = 1; i < n; i++) {
        if(i + z[i] == n) v.push_back(i);   
    }
    if(v.size()==0) cout << "Just a legend";
    else if(v.size()==1) {
        bool possible = false;
        for(int i = 1; i < v[0]; i++) {
            if(z[i] >= z[v[0]]) {
                possible = true;
                break;
            }
        }
        if(!possible) cout << "Just a legend";
        else {
            for(int i = 0; i < z[v[0]]; i++) cout << s[v[0] + i];
        }
    }
    else {
        sort(v.begin(), v.end());
        // Check for z[v[0]].
        bool first = false;
        for(int i = 1; i < n - z[v[0]]; i++) {
            if(z[i] >= z[v[0]]) first = true;
        }
        if(first) {
            for(int i = n - z[v[0]]; i < n; i++) cout << s[i];
        }
        else {
            for(int i = n - z[v[1]]; i < n; i++) cout << s[i];
        }
    }
}