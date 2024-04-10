#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int D = 1;
int x[MAXN];
set<int> C;
stack<int> S;

void freeS() {
    while (!S.empty() && S.top() == D) {
        ++D;
        S.pop();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) C.insert(i);

    for (int i = 0; i < K; ++i) {
        cin >> x[i];
        C.erase(x[i]);
        if (x[i] == D) {
            ++D;
            freeS();
            continue;
        }
        if (!S.empty() && S.top() < x[i]) {
            cout << "-1" << endl;
            return 0;
        }
        S.push(x[i]);
    }

    for (int i = K; i < N; ++i) {
        set<int>::iterator iter;
        if (S.empty()) iter = C.end(); else iter = C.upper_bound(S.top());
        --iter;
        x[i] = *iter;
        C.erase(iter);
        S.push(x[i]);
        freeS();
    }

    for (int i = 0; i < N; ++i) cout << x[i] << " ";
    cout << endl;

    return 0;
}