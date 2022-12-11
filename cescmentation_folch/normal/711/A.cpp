#include<bits/stdc++.h> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    char a[n][4];
    char mander;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        cin >> mander;
        cin >> a[i][2] >> a[i][3];
    }
    bool yes = false;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == 'O' and a[i][1] == 'O') {
            a[i][0] = '+';
            a[i][1] = '+';
            yes = true;
            break;
        }
        if (a[i][2] == 'O' and a[i][3] == 'O') {
            a[i][2] = '+';
            a[i][3] = '+';
            yes = true;
            break;
        }
    }
    if (yes) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i][0] << a[i][1];
            cout << mander;
            cout << a[i][2] << a[i][3] << endl;
        }
    }
    else cout << "NO" << endl;
}