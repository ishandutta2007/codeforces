#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;
char str[2000];
char ans[2000];
int x, y;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ans[2*n-2] = 0;
    x = n, y = n;
    int ptr = 2*n-3;
    while(x+y-2 >= n) {
        if(y > 1) {
            cout << "? 1 1 " << x << " " << y-1 << endl;
            cin >> str;
            while(str[0] == 'B');
        } else {
            str[0] = 'N';
        }
        if(str[0] == 'Y') {
            ans[ptr--] = 'R';
            --y;
        } else {
            ans[ptr--] = 'D';
            --x;
        }
        /*cout << "1 1 " << x-1 << " " << y << endl;
        cin >> str; */
    }
    cerr << "!! " << x << " " << y << endl;
    ptr = 0;
    x = 1, y=1;
    while(2*n-x-y-1 >= n-1) {
        if(x < n) {
            cout << "? " << x+1 << " " << y << " " << n << " " << n << endl;
            cin >> str;
            while(str[0] == 'B');
        } else {
            str[0] = 'N';
        }
        
        if(str[0] == 'Y') {
            ans[ptr++] = 'D';
            ++x;
        } else {
            ans[ptr++] = 'R';
            ++y;
        }
    }
    cerr << "!! " << x << " " << y << endl;
    cout << "! "<< ans << endl;
    return 0;
}