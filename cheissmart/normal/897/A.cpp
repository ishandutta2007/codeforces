#include <iostream>

using namespace std;

int main()
{
    int n, m, l, r;
    char c1, c2;
    string s;
    cin >> n >> m >> s;
    while(m--) {
        cin >> l >> r >> c1 >> c2;
        l--, r--;
        for(int i=l;i<=r;i++) if(s[i] == c1) s[i] = c2;
    }
    cout << s << endl;
}