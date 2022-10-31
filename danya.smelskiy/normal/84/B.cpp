#include <bits/stdc++.h>
using namespace std;

long long n,last;
int a[100005];
long long ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        ++last;
        if (a[i]!=a[i+1] || i==n) {
            ans+=(last)*(last+1)/2;
            last=0;
        }
    }
    cout<<ans;
}