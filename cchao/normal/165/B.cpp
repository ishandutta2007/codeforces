#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b;
int ok(ll v){
    ll k = 1, sum=v, xd = v;
    while(xd){
        k *= b;
        xd = v/k;
        sum += xd;
    }
    if(sum >= a) return 1;
    return 0;
}
int main(){
    cin >> a >> b;
    ll l = 0, r = 10000000000, mid, last;
    while(l < r){
        mid = (l+r)/2;
        if(ok(mid)) r = mid, last = mid;
        else l = mid+1;
    }
    cout << last << endl;
    return 0;
}