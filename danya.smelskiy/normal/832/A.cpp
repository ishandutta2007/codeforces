#include <bits/stdc++.h>
using namespace std;
long long n,k;

int main(){

    cin>>n>>k;
    k=n/k;
    if (k%2==0) cout<<"NO";
    else cout<<"YES";
}