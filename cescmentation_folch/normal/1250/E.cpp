#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector <pair <char, int> >v;
    v.push_back({s[0], 1});
    for (int i = 1; i < n; ++i) {
        if (s[i] == v[v.size()-1].first) ++ v[v.size()-1].second;
        else v.push_back({s[i], 1});
    }
    int m = v.size();
    
    
    if (m%2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    bool pos = true;
    for (int i = 0; 2*i < m-1; ++i) {
        if (v[i].first != v[m-1-i].first || v[i].second + v[m-1-i].second < 3) pos = false;
    }
    if (!pos || v[m/2].second < 2) {
        cout << 0 << endl;
        return 0;
    }
    cout << v[m/2].second+1 << endl;
}