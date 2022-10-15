#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
int n,ap[105],x,ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>x;
        ap[x]++;
        ans=max(ans,ap[x]);
    }
    cout<<ans<<"\n";
    return 0;
}