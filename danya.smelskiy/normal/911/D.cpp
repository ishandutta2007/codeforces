#include <bits/stdc++.h>
using namespace std;


int n,m;
int ans;
int a[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        for (int j=1;j<i;++j)
            if (a[j]>a[i]) ++ans;
    }
    ans%=2;
    cin>>m;
    while (m--) {
        int l,r;
        cin>>l>>r;
        int x=(r-l+1)*(r-l)/2;
        if (x%2) ans^=1;
        if (ans) cout<<"odd"<<'\n';
        else cout<<"even"<<'\n';
    }
}