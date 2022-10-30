#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long ans;
long long a[100001];
long long last;

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i){
        int z=a[i]/k;
        if (z==0) continue;
        if (z%2==0) {
            a[i]%=k;
            ans+=z/2;
        } else {
            ans+=z/2;
            ++last;
            a[i]%=k;
        }
    }
    for (int i=1;i<=n;++i){
        if (a[i]>0) ++last;
    }
    ans+=last/2+last%2;
    cout<<ans;
}