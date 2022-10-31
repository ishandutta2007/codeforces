#include <iostream>
using namespace std;
typedef long long ll;


int main() {
    ll n; cin >> n;
    ll ans = 0;
    ll y = 1;
    while(n%y==0) y*=3;
    ans = (n+(y-1))/y;

    cout << ans << endl;
    return 0;
}