#include <bits/stdc++.h>
using namespace std;

int n,k;
int ans[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        ans[i*2-1]=i*2;
        ans[i*2]=i*2-1;
    }
    int x=n-k-k;
    for (int i=1;i<=n;++i) {
        int z=n-i;
        if (i-z==x) {
            for (int j=i+1;j<=n;++j)
                swap(ans[j+j],ans[j+j-1]);
            break;
        }
    }
    for (int i=1;i<=n+n;++i)
        cout<<ans[i]<<" ";
}