/************
*           *
*   HELLO   *
*           *
************/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = 0;
    char c[10000][5];
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<5; j++) {
            cin >> c[i][j];
        }
        if (flag == 0) {
            if ((c[i][0] == 'O')&&(c[i][1] == 'O')) {
                flag = 1;
                c[i][0] = '+';
                c[i][1] = '+';
            }
            else {
                if ((c[i][3] == 'O')&&(c[i][4] == 'O')) {
                    flag = 1;
                    c[i][3] = '+';
                    c[i][4] = '+';
                }
            }
        }
    }
    if (flag == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<5; j++) {
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}