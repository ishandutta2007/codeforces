//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    string s;
    cin >> s;
    int n = s.length();
    int hasAdjOnes = -1;
    int hasAdjZeroes = -1;
    forn(i, n-1) {
        if(s[i+1]=='1'&&s[i]=='1') {
            hasAdjOnes = i;
            break;
        } 
    }
    for(int i=(n-2); i>=0; i--) {
        if(s[i+1]=='0'&&s[i]=='0') {
            hasAdjZeroes = i;
            break;
        }
    }
    // cout << hasAdjOnes << " " << hasAdjZeroes << endl;
    if(hasAdjOnes>=0&&hasAdjZeroes>=0) {
        if(hasAdjZeroes>hasAdjOnes) {
            cout << "NO";
        }
        else {
            cout << "YES";
        }
    }
    else {
        cout << "YES";
    }
    cout << endl;
}
    return 0;
}