#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    long long gcd=0;
    for(int i=1;i<n;i++)gcd=__gcd(gcd,abs(a[i]-a[i-1]));
    for(int i=0;i<m;i++){
        long long x;
        cin>>x;
        cout<<__gcd(x+a[0],gcd)<<' ';
    }
    return 0;
}