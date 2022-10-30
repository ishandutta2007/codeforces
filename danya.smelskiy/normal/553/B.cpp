#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long f[1005];

int sz;


int main() {
    cin>>n>>k;
    f[0]=1;
    f[1]=1;
    sz=1;
    while (true) {
        ++sz;
        f[sz]=f[sz-1]+f[sz-2];
        if (sz==50) break;
    }
    for (int i=1;i<=n;) {
        if (f[n-i]>=k) {
            cout<<i<<" ";
            ++i;
        } else {
            cout<<i+1<<" "<<i<<" ";
            k-=f[n-i];
            i+=2;
        }
    }
}