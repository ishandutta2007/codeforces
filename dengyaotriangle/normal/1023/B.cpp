#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    long long n,k;
    cin>>n>>k;
    long long lb=max(k-n,1ll);
    long long ub=min((k-1)/2,n);
    cout<<max(0ll,ub-lb+1);
    return 0;
}