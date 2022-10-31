#include <bits/stdc++.h>
using namespace std;
long long n,x,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        long long l=0;
        long long r=x;
        while (l<r-1){
            long long mid=(l+r)/2;
            if ((mid)*(mid+1)/2<=x) l=mid;
            else r=mid;
        }
        if ((r)*(r+1)/2<=x) l=r;
        ans^=l;
    }
    if (ans) cout<<"NO";
    else cout<<"YES";
}