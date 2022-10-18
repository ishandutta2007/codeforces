#include<bits/stdc++.h>

using namespace std;

long long n,m;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    long long miv=max(0ll,n-(m<<1)),mxv=0;
    for(long long i=0;i<=n;i++){
        if(((i*(i-1))>>1)>=m) mxv=max(mxv,n-i);
    }
    cout<<miv<<' '<<mxv;
    return 0;
}