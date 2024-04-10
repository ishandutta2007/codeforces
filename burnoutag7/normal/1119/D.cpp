#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q;
ll s[100005];
ll f[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    for(int i=1;i<n;i++){
        s[i]=s[i+1]-s[i];
    }
    sort(s+1,s+1+n);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+s[i];
    }
    cin>>q;
    while(q--){
        ll l,r,len;
        cin>>l>>r;
        len=r-l+1;
        int pos=upper_bound(s+1,s+n,len)-(s+1);
        cout<<f[pos]+(n-pos)*len<<endl;
    }

    return 0;
}