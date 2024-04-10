#include <iostream>
using namespace std;

bool h[310]={};
int n, p;

int main() {
    int n, p, ans=-1;
    cin >> p >> n;
    for(int i = 1; i <= n; ++i) {
        int t; cin >> t; t %= p;
        if(h[t]&&ans==-1) {
            ans=i;
        }
        h[t] = true;
    }
    cout << ans << endl;
    return 0;
}