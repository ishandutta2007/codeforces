#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi A;
        vi B;
        for (int i = 1; i <= n; i += 2) {
            if (i == n) {
                A.push_back(i);
                B.push_back(i);
            }
            else {
                cout << "? " << i << ' ' << i + 1 << endl;
                char a;
                cin >> a;
                if (a == '>') {
                    A.push_back(i);
                    B.push_back(i + 1);
                }
                else {
                    A.push_back(i + 1);
                    B.push_back(i);
                }
            }
        }
        int ma = A[0];
        for (int i = 1; i < (int)A.size(); ++i) {
            cout << "? " << ma << ' ' << A[i] << endl;
            char a;
            cin >> a;
            if (a == '<') ma = A[i];
        }
        int mi = B[0];
        for (int i = 1; i < (int)B.size(); ++i) {
            cout << "? " << mi << ' ' << B[i] << endl;
            char a;
            cin >> a;
            if (a == '>') mi = B[i];
        }
        cout << "! " << mi << ' ' << ma << endl;
    }
}