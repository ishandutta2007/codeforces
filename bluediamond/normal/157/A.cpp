#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=35;

int r[N],c[N],v[N][N],n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>v[i][j];
            r[i]+=v[i][j];
            c[j]+=v[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            ans+=(c[j]>r[i]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}