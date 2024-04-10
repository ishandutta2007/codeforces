#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    s += 'A';
    int lv = -1;
    int ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U' ||s[i] == 'Y') {
            ans = max(ans,i-lv);
            lv = i;
        }
    }
    cout << ans << "\n";
}