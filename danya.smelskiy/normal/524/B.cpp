#include <bits/stdc++.h>
using namespace std;

int n;
int x[1005],y[1005];
long long ans;

inline void check(long long xx,int j,long long sum){
    for (int i=1;i<=n;++i) if (i!=j) {
        if (min(x[i],y[i])>xx) return;
        if (x[i]>xx) sum+=x[i];
        else if (y[i]>xx) sum+=y[i];
        else sum+=min(x[i],y[i]);
    }
    ans=min(ans,xx*sum);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x[i]>>y[i];
    }
    ans=1e18;
    for (int i=1;i<=n;++i){
        check(y[i],i,x[i]);
        check(x[i],i,y[i]);
    }
    cout<<ans;
}