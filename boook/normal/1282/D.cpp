#include <bits/stdc++.h>
using namespace std;

int query(string s) {
    assert(s.size() <= 300);
    cout << s << endl;
    cout.flush();
    int ans;
    cin >> ans;
    if (ans == 0) exit(0);
    return ans;
}
int main() {
    
    int len = query("a"), val;
    
    string tmp;
    for (int i = 1; i <= min(300, len + 1); ++ i) tmp += "a";

    val = query(tmp);
    if (val == len + 1) {
        tmp = "";
        for (int i = 1; i <= len; ++ i) tmp += "b";
        query(tmp);
    }

    for (int i = 0; i < tmp.size(); ++ i) {
        tmp[i] = 'b';
        int now = query(tmp);
            
        if (now > val) tmp[i] = 'a';
        else val = now;
    }
    

    return 0;
}