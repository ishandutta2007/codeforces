#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n --) {
        string s;
        cin >> s;
        map<int, int> cc, dd;
        int sum = 0;
        for (int i = 0; i < s.size(); ++ i) {
            cc[s[i] - '0'] ++;
            sum += s[i] - '0';
        }
        int ok = 1;
        if (cc[0] == 0) ok = 0;
        else {
            cc[0] --;
            if (sum % 3 != 0) ok = 0;
            int cnt = 0;
            for (int i = 0; i < 10; i += 2) if (cc[i] > 0) cnt ++;
            if (cnt == 0) ok = 0;
        }
        if (ok) cout << "red" << "\n";
        else cout << "cyan" << endl;
    }
    return 0;
}