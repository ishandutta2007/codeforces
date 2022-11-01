#include<bits/stdc++.h>
using namespace std;

int n,q,k,a[100005];
long long pre[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i+1]-a[i-1]-2;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l!=r)cout<<(long long)a[l+1]-2+k-a[r-1]-1+pre[r-1]-pre[l]<<'\n';
        else cout<<k-1<<'\n';
    }

    return 0;
}