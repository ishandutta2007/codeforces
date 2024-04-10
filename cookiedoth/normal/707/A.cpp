#include <iostream>

using namespace std;

int main()
{
    int n, m, flag = 0, i;
    char c;
    cin >> n >> m;
    for (i = 0; i<n*m; i++) {
        cin >> c;
        if (c=='C'||c=='M'||c=='Y') {
            flag++;
        }

    }
    if (flag == 0) cout << "#Black&White";
    else cout << "#Color";
    return 0;
}