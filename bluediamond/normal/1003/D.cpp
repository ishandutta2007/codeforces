#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int ap[35];
int n,q,x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>x;
        ap[(int)log2(x)]++;
    }
    while(q--) {
        int x;
        cin>>x;
        int ans=0;
        for(int i=30;i>=0;i--) {
            int p=(1<<i);
            int need=x/p;
            int t=min(need,ap[i]);
            ans+=t;
            x-=t*p;
        }
        if(x==0)
            cout<<ans<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}