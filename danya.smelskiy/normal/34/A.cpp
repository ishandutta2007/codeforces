#include <bits/stdc++.h>
using namespace std;
long long n,a[1000001],f,s,ans=10000000000000000;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (i>1 && abs(a[i]-a[i-1])<ans){
            ans=abs(a[i]-a[i-1]);
            f=i-1;
            s=i;
        }
    }
    if (abs(a[n]-a[1])<ans) cout<<n<<" "<<1;
    else cout<<f<<" "<<s;
}