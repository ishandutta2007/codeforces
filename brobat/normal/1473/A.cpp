#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        int n,d,temp;
        cin >> n >> d;
        multiset <int> ms;
        for (int j=1; j<=n; j++) {
            scanf("%d",&temp);
            ms.insert(temp);
        }
        int t = *ms.begin() + *++ms.begin();
        if (*--ms.end() <= d) {
            cout << "YES\n";
        } else {
            if (t > d) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}