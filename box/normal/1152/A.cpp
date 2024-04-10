#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int ne = 0, no = 0, me = 0, mo = 0;
    while(n--) {
        int i; cin >> i;
        if(i&1) no++;
        else ne++;
    }
    while(m--) {
        int i; cin >> i;
        if(i&1) mo++;
        else me++;
    }
    cout << min(ne, mo) + min(me, no) << endl;
}