#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,cnt=0; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]==1) {
            cnt++;
        }
    }
    if(cnt) {
        cout<<n-cnt<<"\n";
        return 0;
    }
    int ans=(1<<30);
    for(int st=0;st<n;st++) {
        int g=v[st];
        for(int dr=st+1;dr<n;dr++) {
            g=__gcd(g,v[dr]);
            if(g==1) {
                ans=min(ans,dr-st+1);
            }
        }
    }
    if(ans==(1<<30)) cout<<"-1\n";
    else cout<<ans+n-2<<"\n";
    return 0;
}
/**


**/