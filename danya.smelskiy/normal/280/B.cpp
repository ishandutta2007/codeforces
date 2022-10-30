#include <bits/stdc++.h>
using namespace std;

int n,sz;
int a[100005];
int q[100005];
int ans;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    sz=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        while (sz && q[sz]<a[i]) {
            ans=max(ans,q[sz--]^a[i]);
        }
        if (sz) ans=max(ans,q[sz]^a[i]);
        q[++sz]=a[i];
    }
    cout<<ans;
}