#include <iostream>
#include <cstdio>
using namespace std;

int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    string s;
    cin >> s;
    if (s.length() == 1 && s[0] == '0'){
        cout << 0 << endl;
        return 0;
    }
    bool flag = false;
    for (int i = 1; i < s.length(); ++ i)
        if (s[i] != '0'){
            flag = true;
            break;
        }
    if (flag) cout << (s.length() + 1) / 2 << endl;
    else cout << s.length() / 2 << endl;
}