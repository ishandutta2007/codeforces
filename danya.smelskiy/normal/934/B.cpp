#include <bits/stdc++.h>
using namespace std;


long long n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n>36) {
        cout<<"-1";
        return 0;
    }
    long long res=0;
    while (n) {
        if (n==1) {
            res*=10;
            res+=4;
            n--;
        } else {
            res*=10;
            res+=8;
            n-=2;
        }
    }
    cout<<res;
}