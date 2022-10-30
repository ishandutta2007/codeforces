#include <bits/stdc++.h>
using namespace std;
long long n,s;
inline bool check(long long x){
    long long sum=0;
    long long y=x;
    while (y) {
        sum+=y%10;
        y/=10;
    }
    return x-sum>=s;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    long long l=1;
    long long r=n+1;
    while (l<r) {
        long long mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<n-r+1;
}