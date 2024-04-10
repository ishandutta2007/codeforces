/**************
*             *
*    HELLO    *
*             *
**************/

#include <iostream>
#include <string>

using namespace std;

const int mx = 100;

int main()
{
    int n, p[mx], i, j, k;
    bool res = 1;
    cin >> n;
    for (i = 0; i<n; i++) {
        cin >> p[i];
    }
    string s;
    getline(cin, s);
    for (i = 0; i<n; i++) {
        getline(cin, s);
        k = 0;
        for (j = 0; j<s.length(); j++) {
            if ((s[j]=='a')||(s[j]=='o')||(s[j]=='u')||(s[j]=='e')||(s[j]=='i')||(s[j]=='y')) {
                k++;
            }
        }
        if (k!=p[i]) {
            res = 0;
        }
    }
    if (res == 0) cout << "NO";
    else cout << "YES";
    return 0;
}