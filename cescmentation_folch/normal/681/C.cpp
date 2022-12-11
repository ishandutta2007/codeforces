#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1000010;

int D[MAX];
int N[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> S;
    int kk = 0;
    for(int i = 0; i < n; ++i) {
         string a;
         cin >> a;
         if (a == "insert") {
             int x;
             cin >> x;
             S.push(-x);
             D[kk] = 1;
             N[kk] = x;
             ++kk;
        }
        else if (a == "removeMin") {
            if (S.empty()) {
                D[kk] = 1;
                N[kk] = 1;
                kk++;
            }
            else S.pop();
            D[kk] = 2;
            kk++;
        }
        else {
            int x;
            cin >> x;
            if (S.empty() or -S.top() > x) {
                S.push(-x);
                D[kk] = 1;
                N[kk] = x;
                kk++;
            }
            else if (-S.top() < x) {
                while (!S.empty() and -S.top() < x) {
                    D[kk] = 2;
                    kk++;
                    S.pop();
                }
                if (S.empty() or -S.top() > x) {
                    S.push(-x);
                    D[kk] = 1;
                    N[kk] = x;
                    kk++;
                }
            }
            D[kk] = 3;
            N[kk] = x;
            kk++;
        }
    }
    cout << kk << '\n';
    for (int i = 0; i < kk; ++i) {
        if (D[i] == 1) {
            cout << "insert " << N[i] << '\n'; 
        }
        else if (D[i] == 2) {
            cout << "removeMin" << '\n';
        }
        else {
            cout << "getMin " << N[i] << '\n';
        }
    }
}