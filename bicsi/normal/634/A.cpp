#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

vector<int> A, B;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, a, b, start;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> a;
        if(a > 0) {
            A.push_back(a);
        }
    }

    for(int i=1; i<=n; i++) {
        cin >> b;
        if(b > 0) {
            B.push_back(b);
        }
    }

    if(A.size() != B.size()) {
        cout << "NO";
        return 0;
    }

    int s;
    for(s=0; s<B.size() && B[s] != A[0]; s++);

    if(s == B.size()) {
        cout << "NO";
        return 0;
    }

    for(int i=s; i<s+B.size(); i++) {
        if(B[i % B.size()] != A[i-s]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}