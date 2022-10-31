#include <bits/stdc++.h>
using namespace std;

long long n,m;

int main(){
    cin>>n>>m;
    if (m==1) {
        cout<<n;
        return 0;
    }
    long long sz=0;
    while (n) {
        sz++;
        n>>=1ll;
    }
    cout<<(1ll<<sz)-1ll;
}