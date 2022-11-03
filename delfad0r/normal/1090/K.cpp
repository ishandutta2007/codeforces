#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << v << ", ";
    }
    out << "]";
    return out;
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

int getmask(string t){
    int m = 0;
    for(char c:t){
        m |= (1<<(c-'a'));
    }
    return m;
}
bool findm(char c, int mask){
    return mask & (1 << (c-'a'));
}

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> s(n+1);
    vector<int> t(n+1);
    vector<pair<pair<string, int>,int>> p;
    for(int i=1; i<=n; i++){
        string sf;
        cin >> s[i] >> sf;
        t[i] = getmask(sf);
        while(s[i].size() > 0 and findm(s[i].back(), t[i])) s[i].pop_back();
        p.emplace_back(pair<string, int>{s[i], t[i]}, i);
    }
    sort(p.begin(), p.end());
    vector<vector<int>> ans;
    vector<int> curr;
    pair<string, int> last = {"", 0};
    for(auto e:p){
        //~ cerr << e.first.first << ' ' << e.first.second << endl;
        if(e.first == last){
            curr.push_back(e.second);
        }else{
            if(curr.size() > 0) ans.push_back(curr);
            curr = {e.second};
        }
        last = e.first;
    }
    ans.push_back(curr);
    cout << ans.size() << '\n';
    for(auto v:ans){
        cout << v.size();
        for(int x:v) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}