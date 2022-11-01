#include<bits/stdc++.h>
using namespace std;

int n,b[1000005];
double ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ans=1e6;
    for(int i=1,a;i<=n;i++){
        cin>>a;
        int len=i-b[a]-1;
        ans-=(double)len*len/n/n;
        b[a]=i;
    }
    for(int i=1;i<=1e6;i++){
        ans-=(double)(n-b[i])*(n-b[i])/n/n;
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';

    return 0;
}