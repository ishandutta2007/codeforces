#include <iostream>
#include <queue>
#define itstep 6235300

using namespace std;

queue<int> q1;
queue<int> q2;

int main() {
    int n; cin >> n;
    int k1; cin >> k1;
    while(k1--) {
        int v; cin >> v;
        q1.push(v);
    }
     cin >> k1;
    while(k1--) {
        int v; cin >> v;
        q2.push(v);
    }
    for(int i=0; i<=itstep; i++) {
        if(q1.empty()) {
            cout << i << " 2" << endl;
            return 0;
        }
        if(q2.empty()) {
            cout << i << " 1" << endl;
            return 0;
        }
        int t1 = q1.front(); q1.pop();
        int t2 = q2.front(); q2.pop();
        if(t1 > t2) {
            q1.push(t2); q1.push(t1);
        } else {
            q2.push(t1); q2.push(t2);
        }
    }
    cout << -1 << endl;
}