#include <iostream>
#include <set>
using namespace std;

set<int> s;
int lim;
int cval[21];

bool attemptInsert(int p2) {
    int mt = 1<<(p2+1), v = 1<<p2, i = cval[p2];
    while(1) {
        if(v+mt*cval[p2] > lim) {
            if(p2 == 0) return false;
            else return attemptInsert(p2-1) && attemptInsert(p2-1);
        }
        if(s.count(v+mt*cval[p2]) == 0) {
            s.insert(v+mt*cval[p2]);
            return true;
        }
        cval[p2]++;
    }
}

int main() {
    int sum; cin >> sum >> lim;
    for(int i=20; i>=0; i--) {
        if(sum & (1<<i)) {
            if(!attemptInsert(i)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << s.size() << endl;
    bool first = true;
    for(int i:s) {
        if(!first) cout << ' ';
        first = false; cout << i;
    }
    cout << endl;
}