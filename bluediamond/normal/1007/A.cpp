#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000;

int n,v[N+5];
bool viz[N+5];
int ans=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    int p2=1;
    for(int i=1;i<=n;i++) {
        while(p2<n && v[p2]<=v[i] ) {
            p2++;
        }
        while(p2<n && viz[p2]==1) {
            p2++;
        }
        if(viz[p2]==0 && v[p2]>v[i]) {
            ans++;
            viz[p2]=1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/