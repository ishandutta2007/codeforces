#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long a1,a2,a3;
    if((2*n)%k) a1=(2*n)/k+1;
    else a1=(2*n)/k;
    if((5*n)%k) a2=(5*n)/k+1;
    else a2=(5*n)/k;
    if((8*n)%k) a3=(8*n)/k+1;
    else a3=(8*n)/k;
    cout<<a1+a2+a3;
    return 0;
}