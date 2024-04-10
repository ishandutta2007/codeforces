#include <bits/stdc++.h>
using namespace std;
int n,last,k;
int main(){
    cin>>n;
    last=1;
    k=1;
    while (last<=n){
        n-=last;
        ++k;
        last+=k;
    }
    cout<<k-1;
}