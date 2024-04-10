#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

int n;
int len;
string s[max_n];
string ans;

int main()
{
    ios_base::sync_with_stdio(false);
    
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> s[i];
    len = s[0].length();
    ans.resize(len);
    for (int i = 0; i < len; ++i) {
        bool good = true;
        char c = '?';
        for (int j = 0; j < n; ++j)
            if (s[j][i] != '?') {
                if (c == '?') {
                    c = s[j][i];
                } else {
                    if (c != s[j][i]) {
                        good = false;
                    }
                }
            }
        if (good) {
            if (c == '?') {
                ans[i] = 'a';
            } else {
                ans[i] = c;
            }
        } else {
            ans[i] = '?';
        }
    }
    cout << ans << endl;
    return 0;
}