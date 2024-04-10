#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5000;
int n,k,v[N+5];
ld ans=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    for(int st=1;st<=n;st++) {
        int s=0;
        for(int i=st;i<=st+k-1;i++)
            s+=v[i];
        for(int dr=st+k-1;dr<=n;dr++) {
            if(dr!=st+k-1)
                s+=v[dr];
            ans=max(ans,(ld)s/(dr-st+1));
        }
    }
    cout<<fixed<<setprecision(100)<<ans<<"\n";
    return 0;
}