#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<string> ans; string t = "";
    for(int i = 0; i < s.length(); ) {
        if(s.substr(i, 3) == "WUB") {
            i += 3;
            if(t != "") ans.push_back(t);
            t = "";
        }
        else t += s[i++];
    }
    if(t != "") ans.push_back(t);
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    return 0;
}