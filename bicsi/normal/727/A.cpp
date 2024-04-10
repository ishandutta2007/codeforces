#include <bits/stdc++.h>

using namespace std;

vector<int> Ans;
bool CanReach(int a, int b, bool output = false) {
    bool ret;
    
    if(a == b) ret = true;
    else if(a > b) ret = false;
    else if(b % 2 == 0) ret = CanReach(a, b / 2, output);
    else if(b % 10 != 1) ret = false;
    else ret = CanReach(a, (b - 1) / 10, output);
    
    Ans.push_back(b);
    return ret;
}

int main() {
    int a, b;
    cin >> a >> b;
    if(!CanReach(a, b)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << Ans.size() << endl;
        for(auto x : Ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}