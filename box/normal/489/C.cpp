#include <iostream>
#include <string>
using namespace std;

int main() {
    int m, s; cin >> m >> s;
    if(m == 1 && s == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    if(s < 1 || 9*m < s) {
        cout << "-1 -1" << endl;
        return 0;
    }
    int m1 = m, s1 = s;
    string ans;
    while(m1) {
        // choose the least char such that s <= m && 9*m <= s
        int i = 0;
        if(m1 == m) i = 1;
        while(9*(m1-1) < (s1-i) && (i < 10)) i++;
        if(i >= 10) {
            cout << ans << "-1 -1" << endl;
            return 0;
        }
        ans += (i + '0');
        s1 -= i;
        m1--;
    }
    m1 = m, s1 = s;
    ans += ' ';
    while(m1) {
        // choose the greatest char such that s <= m && 9*m <= s
        int i = 9;
        while((s1-i) < 0 && (i >= 0)) i--;
        if(i < 0) {
            cout << ans << "-1 -1" << endl;
            return 0;
        }
        ans += (i + '0');
        s1 -= i;
        m1--;
    }
    cout << ans << endl;
}