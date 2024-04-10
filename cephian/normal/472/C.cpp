#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool str_cmp(string a, string b) {
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<string>> v;
    for(int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        vector<string> t = {a, b};
        sort(t.begin(), t.end());
        v.push_back(t);
    }
    int p[n];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    
    
    string last = "";
    
    bool ok = true;
    for(int i = 0; i < n; ++i) {
        string a = v[p[i]-1][0], b = v[p[i]-1][1];
        if(str_cmp(last, a)) {
            last = a;
            continue;
        }
        if(str_cmp(last, b)) {
            last = b;
            continue;
        }
        ok = false;
        break;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}