#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000;
int n;
ll st,dr,t;
ll a[N+5],b[N+5];
ll ans,bst=(1LL<<60);

void slove(ll poz,ll cost) {
    if(poz+t>=dr)return;
    if(cost<bst) {
        bst=cost;
        ans=poz;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>st>>dr>>t;
    dr++;
    cin>>n;
    if(n==0) {
        slove(st,0);
        if(dr-t<st)
            slove(dr-t-1,st-(dr-t-1));
      ///  cout<<ans<<" , "<<bst<<"\n";
        cout<<ans<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    b[1]=max(st,a[1]);
    for(int i=2;i<=n;i++)
        b[i]=max(b[i-1]+t,a[i]);
    if(a[1]>st)
        slove(st,0);
    else {
        slove(a[1]-1,st-(a[1]-1));
        if(dr-t<a[1])
            slove(dr-t-1,st-(dr-t-1));
    }
    for(int i=2;i<=n;i++) {
        if(a[i]>b[i-1]+t)
            slove(b[i-1]+t,0);
        else
            slove(a[i]-1,b[i]-(a[i]-1));
    }
    slove(b[n]+t,0);
   /// cout<<b[n]<<"\n\n";
   ///cout<<ans<<" "<<bst<<"\n";
    cout<<ans<<"\n";
    return 0;
}
/**

14 17 10
0

st = 4
poz = 3

**/