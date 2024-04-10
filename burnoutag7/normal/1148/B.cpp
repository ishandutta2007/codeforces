#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,ta,tb,k;
ll a[200005];
ll b[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>ta>>tb>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>b[i];
    }
    ll ans=0;
    for(ll i=0;i<=k;i++){
        if(i+1>n){
            cout<<-1<<endl;
            return 0;
        }
        ll start=a[i+1]+ta;
        if(start>b[m]){
            cout<<-1<<endl;
            return 0;
        }
        ll lft=k-i;
        ll pos=lower_bound(b+1,b+1+m,start)-(b+1);
        while(b[pos]<start)pos++;
        if(pos+lft>m){
            cout<<-1<<endl;
            return 0;
        }
        ans=max(ans,b[pos+lft]+tb);
    }
    cout<<ans<<endl;

    return 0;
}