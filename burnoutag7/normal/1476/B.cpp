#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k,p[105];
long long pre,ans;

void solve(){
    cin>>n>>k;
    ans=pre=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        pre+=p[i-1];
        if(i!=1)ans=max(ans,(p[i]*100ll+k-1)/k-pre);
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)solve();

    return 0;
}