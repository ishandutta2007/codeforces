#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int M = 50;
ll A[M][2];

int main() {
    ll a, b;
    cin >> a >> b;
    ll ina = a;
    ll inb = b;
    if (a%2 and b%2) {
        A[0][0] = 2;
        A[0][1] = 0;
    }
    else if (a%2) {
        A[0][0] = 0;
        A[0][1] = 0;
    }
    else if (b%2) {
        A[0][0] = 0;
        A[0][1] = 0;
    }
    else {
        A[0][0] = 1;
        A[0][1] = 1;
    }
    a /= 2;
    b /= 2;
    for (int i = 0; i < M; ++i) {
        int ak = a%2;
        int bk = b%2;
        if (bk and ak) {
            A[i + 1][1] = 0;
            A[i + 1][0] = 2*A[i][0];
        }
        else if (bk and ak == 0) {
            A[i + 1][1] = 2*A[i][1];
            A[i + 1][0] = 0;
        }
        else if (bk == 0 and ak) {
            A[i + 1][1] = A[i][1];
            A[i + 1][0] = A[i][1];
        }
        else {
            A[i + 1][1] = A[i][0];
            A[i + 1][0] = A[i][0];
        }
        a /= 2;
        b /= 2;
        if (a == 0 and b == 0) { 
            if (ina == inb) cout << A[i + 1][0] - 2 << endl;
            else if (inb == 0) {
                if (ina%2) cout << 0 << endl;
                else cout << 1 << endl;
            }
            else cout << A[i + 1][0] << endl;
            break;
        }
        else if (a == 0){
            cout << 0 << endl;
            break;
        }
    }
}