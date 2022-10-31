#include <bits/stdc++.h>
using namespace std;
long long n,k,l,r,last;
int main(){
    cin>>n>>k;
    l=1;
    r=n;
    last=2;
    for (int i=1;i<=n;++i){
        if (i<=k){
            if (last==2){
                cout<<l<<" ";
                ++l;
                last=1;
            } else {
                cout<<r<<" ";
                --r;
                last=2;
            }
        } else {
            if (last==2){
                cout<<r<<" ";
                --r;
            } else {
                cout<<l<<" ";
                ++l;
            }
        }
    }
}