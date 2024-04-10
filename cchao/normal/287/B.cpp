#include <iostream>
using namespace std;
typedef long long ll;
ll n, k;
ll solve(){
    if(k*(k+1)/2<n) return -1;
    ll l = 0, r = k, mid = (l + r)/2, last = mid;
    while(l <= r){
        mid = (l+r)/2;
//      cout << l << ' ' << r << ' ' << mid << endl;
        if(k*(k+1)/2 - mid*(mid+1)/2 >= n) l = mid+1, last = mid;
        else r = mid-1;
    }
//  cout << l << ' ' << r << '-' << mid << endl;
    return k-last;
}
int main(){
    cin >> n >> k;
    n--, k--;
    cout << solve() << endl;
    return 0;
}