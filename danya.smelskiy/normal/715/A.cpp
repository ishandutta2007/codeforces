#include <bits/stdc++.h>
using namespace std;

long long n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<"2 ";
    for (long long i=2;i<=n;++i) {
        cout<<i*(i+1ll)*(i+1ll)-(i-1ll)<<" ";
    }
}