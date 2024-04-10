#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
ll a[200005],s;

ll get(ll x,ll y){
    int firstgood=lower_bound(a,a+n,x)-a;
    ll res=2e18;
    for(int i=max(0,firstgood-1);i<min(n,firstgood+2);i++){
        res=min(res,max(0ll,y-(s-a[i]))+max(0ll,x-a[i]));
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    sort(a,a+n);
    cin>>m;
    while(m--){
        ll x,y;
        cin>>x>>y;
        cout<<get(x,y)<<'\n';
    }

    return 0;
}