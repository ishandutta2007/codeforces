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
int balance;
char ans[120000];

int main()
{
    int b, g;
    cin >> n >> k >> g >> b;
    balance = 0;
    for (int i = 0; i < n; ++i) {
        if (balance <= -k) {
            if (b > 0) {
                ans[i] = 'B';
                b--;
                balance = 1;
                continue;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        if (balance >= k) {
            if (g > 0) {
                ans[i] = 'G';
                g--;
                balance = -1;
                continue;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        if (b >= g) {
            ans[i] = 'B';
            b--;
            if (balance < 0) balance = 1;
            else balance++;
            continue;
        }
        else {
            ans[i] = 'G';
            g--;
            if (balance > 0) balance = -1;
            else balance--;
            continue;
        }
    }
    cout << ans;
    return 0;
}