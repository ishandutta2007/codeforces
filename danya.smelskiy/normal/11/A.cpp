#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int ans,d;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (i==1 || a[i]>a[i-1]) continue;
        int len=a[i-1]-a[i];
        len=(len/d)+1;
        ans+=len;
        a[i]+=len*d;
    }
    cout<<ans;
}