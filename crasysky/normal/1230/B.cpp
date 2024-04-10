#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
string s;
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read(), k = read();
    cin >> s;
    if (k == 0){
        cout << s << endl;
        return 0;
    }
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    if (s[0] != '1'){
        -- k;
        s[0] = '1';
    }
    if (k == 0){
        cout << s << endl;
        return 0;
    }
    for (int i = 1; i < n; ++ i)
        if (s[i] != '0'){
            s[i] = '0';
            if ((-- k) == 0)
                break;
        }
    cout << s << endl;
}