#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
int main(){
    cin>>n>>m;
    if (m<n) { cout<<n-m; return 0;}
    if (n<m) swap(n,m);
    while (true){
        if (n==m) {
            cout<<ans;
            return 0;
        }
        if (n<m){
            cout<<ans+m-n;
            return 0;
        }
        if (n%2==0) n/=2; else { n++; }

        ++ans;
    }
}