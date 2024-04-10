#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;



int n,m;
vector<int> v[1000005];
long long f[1000005];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        while (x--) {
            int y;
            cin>>y;
            v[y].push_back(i);
        }
    }
    sort(v+1,v+m+1);
    f[0]=1;
    for (int i=1;i<=m;++i)
        f[i]=(f[i-1]*1ll*i)%md;
    int i=1;
    long long ans=1;
    while (i<=m) {
        int j=i;
        while (j<=m && v[j]==v[i]) ++j;
        ans=(ans*f[j-i])%md;
        i=j;
    }
    cout<<ans;
}