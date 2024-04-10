#include <bits/stdc++.h>
using namespace std;

long long n,t,k,d;
int main(){
    cin>>n>>t>>k>>d;
    long long ans=(n/k);
    if (n%k!=0) ++ans;
    ans*=t;
    long long z=0;
    long long tt=t;
    long long dd=t;
    while (n>0) {
        ++z;
        if (tt==1) {
            n-=k;
            tt=t;
        } else --tt;
        if (z<=d) continue;
        if (dd==1) {
            n-=k;
            dd=t;
        } else --dd;
    }
    if (ans<=z) cout<<"NO";
    else cout<<"YES";
}