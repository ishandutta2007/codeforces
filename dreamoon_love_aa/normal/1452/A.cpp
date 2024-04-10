#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int x,y;
    cin>>x>>y;
    cout<<x+y+max(0,abs(x-y)-1)<<endl;
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}