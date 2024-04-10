#include <iostream>
using namespace std;

int status[1445]; // status at the i-th second

int main() {
    int n, p1, p2, p3, t1, t2; cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    int f = 0, l = 0;
    for(int i=0; i<n; i++) {
        int s, e; cin >> s >> e; f = e; if(i == 0) l = s;
        for(int t=s; t<e; t++) status[t] = 2;
        for(int t=e; t<e+t1; t++) status[t] = 2;
        for(int t=e+t1; t<e+t1+t2; t++) status[t] = max(status[t], 1);
    }
    int tot = 0;
    for(int i=l; i<f; i++) {
        if(status[i] == 2) tot += p1;
        if(status[i] == 1) tot += p2;
        if(status[i] == 0) tot += p3;
    }
    cout << tot << endl;
}