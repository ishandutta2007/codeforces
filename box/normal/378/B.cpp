#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct el {
    int val, id;
    bool a;
    const bool operator<(const el o) const {
        return val < o.val;
    }
};

vector<el> th;

bool a1[100005], a2[100005];

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        if(i < n/2) {
            a1[i] = 1;
            a2[i] = 1;
        }
        if(n%2 && i == n/2) {
            if(a < b) a1[i] = 1;
            else a2[i] = 1;
        }
        th.push_back({a, i, true});
        th.push_back({b, i, false});
    }
    sort(th.begin(), th.end());
    for(int i=0; i<n; i++) {
        if(th[i].a) a1[th[i].id] = 1;
        else a2[th[i].id] = 1;
    }
    for(int i=0; i<n; i++) cout << a1[i];
    cout << endl;
    for(int i=0; i<n; i++) cout << a2[i];
    cout << endl;
}