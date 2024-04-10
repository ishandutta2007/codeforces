#include <bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
    cin>>n>>k;
    long long z=n/2;
    if (n%2==1) ++z;
    if (k<=z) cout<<k*2-1;
    else cout<<(k-z)*2;
}