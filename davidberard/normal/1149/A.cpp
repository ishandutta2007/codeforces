#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;
int oc, tc, cc;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        int x;
        cin >> x;
        oc += (x==1);
        tc += (x==2);
    }
    while(oc > 2) {
        oc -= 2;
        cc ++;
    }
    if(tc) {
        --tc;
        cout << "2 ";
    } else if(cc) {
        --cc;
        cout << "1 1 ";
    } else if(oc) {
        --oc;
        cout << "1 ";
    }

    if(oc) {
        --oc;
        cout << "1 ";
    }
    while(tc || cc) {
        if(tc) {
            cout << "2 "; --tc;
        }
        else { cout << "1 1 ";
            --cc;
        }
    }
    if(oc) {
        --oc;
        cout << "1 ";
    }
    cout << endl;
    return 0;
}