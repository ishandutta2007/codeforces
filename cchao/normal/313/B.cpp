#include <iostream>
using namespace std;

int d[100010]={};

int main() {
    string s; cin >> s;

    for(int i = 0; i < s.length() - 1; ++i) {
        if(s[i] == s[i+1])
            d[i+1] = 1;
    }
    for(int i = 1; i < s.length(); ++i) {
        d[i] += d[i-1];
        //cout << d[i] << ' ';
    }
    //cout << endl;

    int n; cin >> n;

    while(n--) {
        int l, r; cin >> l >> r;
        cout << d[r-1] - d[l-1] << endl;
    }
    return 0;
}