#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int ans,ans2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]+1==i) ++ans;
    }
    ans2=ans;
    for (int i=1;i<=n;++i) {
        if (a[i]+1!=i) {
            ans2=max(ans2,ans+1);
            if (a[a[i]+1]+1==i) ans2=max(ans2,ans+2);
        }
    }
    cout<<ans2;
}