#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 2000
#define inf 0x3f3f3f3f

string s;

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> s;
    int fr = 0, ba = s.size() - 1;
    vector<int> sol;
    while (fr < ba) {
        while (fr < ba && s[fr] == ')') fr ++;
        while (fr < ba && s[ba] == '(') ba --;
        if (fr < ba && s[fr] == '(' && s[ba] == ')')
            sol.emplace_back(fr), 
            sol.emplace_back(ba), fr ++, ba --;
    }
    sort(sol.begin(), sol.end());
    if (sol.size() == 0) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << "\n";
        cout << sol.size() << endl;
        for (auto to : sol) cout << to + 1 << " "; cout << "\n";
    }
    return 0;
}