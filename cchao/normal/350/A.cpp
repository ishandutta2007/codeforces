#include <iostream>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    int mi, ma;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(i == 0) mi = ma = t;
        else mi = min(mi, t), ma = max(ma, t);
    }
    int mi2, ma2;   
    for(int i = 0; i < m; ++i) {
        cin >> t;
        if(i == 0) mi2 = ma2 = t;
        else mi2 = min(mi2, t), ma2 = max(ma2, t);
    }
    if(ma >= mi2 || 2 * mi > (mi2 - 1))
        cout << "-1" << endl;
    else {
        while(2 * mi > ma) ma++;
        cout << ma << endl;
    }
    return 0;
}