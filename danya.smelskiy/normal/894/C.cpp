#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int mn=1e9;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    int res=0;
    for (int i=1;i<=n;++i)
        res=__gcd(res,a[i]);
    if (res!=mn) {
        cout<<"-1";
        return 0;
    }
    cout<<n+n-1<<'\n';
    for (int i=1;i<=n;++i){
        if (i>1) cout<<" "<<mn<<" ";
        cout<<a[i];
    }

}