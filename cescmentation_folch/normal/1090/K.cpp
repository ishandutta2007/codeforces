#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    map<pair<string, VI>, VI> dic;
    for (int i = 0; i < n; ++i){
        string s, t;
        cin >> s >> t;
        VI cs(26, 0);
        for (int j = 0; j < int(t.size()); ++j){
            cs[t[j]-'a'] = 1;
        }
        while (s.size() > 0 and cs[s.back()-'a'] > 0) s.pop_back();
        auto rep = make_pair(s, cs);
        dic[rep].push_back(i+1);
    }
    cout << dic.size() << endl;
    for (auto it :dic){
        cout << it.second.size();
        for (int v : it.second) cout << " " << v;
        cout << "\n";
    }
    
}