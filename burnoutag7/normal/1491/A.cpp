#include<bits/stdc++.h>
using namespace std;

int n,q,a[100005],c;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c+=a[i];
    }
    while(q--){
        int t,x;
        cin>>t>>x;
        if(t==1)c=c-a[x]+(a[x]^=1);
        else cout<<(c>=x)<<'\n';
    }

    return 0;
}