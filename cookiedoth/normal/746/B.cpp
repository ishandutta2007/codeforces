/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair

using namespace std;

int n, k;
string s;
char ans[3000];
bool b[3000];

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        ans[i] = 'a';
        b[i] = 0;
    }
    int j;
    for (int i = 0; i < n; ++i) {
        j = -1;
        for (int a = 0; a < n; ++a) {
            if (b[a] == 0) j++;
            if (j == ((n - i - 1) / 2)) {
                k = a;
                break;
            }
        }
        ans[k] = s[i];
        b[k] = 1;
    }
    cout << ans;
    return 0;
}