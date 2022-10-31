#include <bits/stdc++.h>
using namespace std;


int n,k,l,r,sall,sk;
int ans[1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>l>>r>>sall>>sk;
    int z=sk/k;
    int lft=sk%k;
    for (int i=1;i<=k;++i) {
        ans[i]=z;
        if (lft) {
            ans[i]++;
            lft--;
        }
    }
    if (n>k) {
        sall-=sk;
        z=sall/(n-k);
        lft=sall%(n-k);
        for (int i=k+1;i<=n;++i) {
            ans[i]=z;
            if (lft) {
                ++ans[i];
                lft--;
            }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}